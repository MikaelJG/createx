cmake_minimum_required(VERSION 3.16)

project(Createx VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(VERIFICATION_LIBRARY Verification_Library) # new name
# set(rary) # new name

add_subdirectory(src)
add_subdirectory(app)
