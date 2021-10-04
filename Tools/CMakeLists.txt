cmake_minimum_required(VERSION 3.4.1)
project(Tools)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

message("======Configure path ${TARGET_PATH}======")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_PATH})
