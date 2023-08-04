cmake_minimum_required(VERSION 3.16)

project(Createx VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(VERIFICATION_LIBRARY Verification_Library) # new name
set(CREATEX_EXECUTABLE Createx_executable)

# to call option from CLI
# cmake .. -DOPTION=ON

# second argument is a comment,
# no impact.

option(COMPILE_EXE "Whether to compile the createx executable or not")

add_subdirectory(src)
if (COMPILE_EXE)
    add_subdirectory(app)
else()
    message(STATUS "Without executable compiling")
endif()
