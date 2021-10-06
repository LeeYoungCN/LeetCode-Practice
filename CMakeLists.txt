cmake_minimum_required(VERSION 3.4.1)
project(LeetCodePractice)

set(TARGET_NAME LeetCodePractice)
set(LIB_NAME public)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")


set(LEETCODE_PATH    ${CMAKE_CURRENT_SOURCE_DIR}/LeetCode)
set(PUBLIC_FUNC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/public_function)
set(GOOGLE_TEST_PATH ${CMAKE_CURRENT_SOURCE_DIR}/google_test)

include_directories(${PUBLIC_FUNC_PATH}/inc ${GOOGLE_TEST_PATH}/inc)

add_library(${LIB_NAME} STATIC ${PUBLIC_FUNC_SRCS})
add_subdirectory(${PUBLIC_FUNC_PATH})

add_executable(${TARGET_NAME} main.cpp)
add_subdirectory(${LEETCODE_PATH})
file(GLOB USER_LIB ${LIBRARY_OUTPUT_PATH}/*.a)
file(GLOB GTEST_LIB ${GOOGLE_TEST_PATH}/lib/*.a)
target_link_libraries(${TARGET_NAME} ${USER_LIB} ${GTEST_LIB})
