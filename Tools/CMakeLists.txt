cmake_minimum_required(VERSION 3.4.1)
project(Tools)

set(TOOLS_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${TOOLS_ROOT_PATH}/bin)
set(LIBRARY_OUTPUT_PATH ${TOOLS_ROOT_PATH}/lib)
set(CMAKE_CXX_STANDARD 17)

message("======Configure path ${TARGET_PATH}======")
add_subdirectory(${TOOLS_ROOT_PATH}/${TARGET_PATH})
