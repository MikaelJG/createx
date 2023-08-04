cmake_minimum_required(VERSION 3.16)

project(Createx VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(MAIN_SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp) # new name
set(VERIFICATION_LIBRARY Verification_Library) # new name
set(CREATEX_EXECUTABLE Createx_executable)

# to call option from CLI
# cmake .. -DOPTION=ON

# second argument is a comment,
# no impact.
option(COMPILE_EXE "Whether to compile the createx executable or not")
option(COMPILE_TEST "Whether to compile the createx test executable or not")

add_subdirectory(src)
if (COMPILE_EXE)
    add_subdirectory(app)
else()
    message(STATUS "Without executable compiling")
endif()

if (COMPILE_TEST)
    add_subdirectory(test)
else()
    message(STATUS "Without testing executable compiling")
endif()
