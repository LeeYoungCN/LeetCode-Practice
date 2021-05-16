cmake_minimum_required(VERSION 3.4.1)
project(LeetCodePractice)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_C_COMPILER "D:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Program Files/mingw64/bin/g++.exe")
set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
