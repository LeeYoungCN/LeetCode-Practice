cmake_minimum_required(VERSION 3.4.1)
project(LeetCodePractice)

set(TARGET_NAME LeetCodePractice)
set(LIB_NAME public)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(LEETCODE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/LeetCode)
set(PUBLIC_FUNC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/public_function)

include_directories(${PUBLIC_FUNC_PATH}/include)

add_library(${LIB_NAME} STATIC ${PUBLIC_FUNC_SRCS})
add_executable(${TARGET_NAME} main.cpp)

add_subdirectory(${PUBLIC_FUNC_PATH})
add_subdirectory(${LEETCODE_PATH})

target_link_libraries(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/lib${LIB_NAME}.a)
