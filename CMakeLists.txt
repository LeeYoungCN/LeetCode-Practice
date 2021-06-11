cmake_minimum_required(VERSION 3.4.1)
project(LeetCodePractice)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(LEETCODE_PATH ${PROJECT_SOURCE_DIR}/LeetCode)
set(PUBLIC_FUNC_PATH ${PROJECT_SOURCE_DIR}/public_function)

include_directories(${LEETCODE_PATH}/include)
include_directories(${PUBLIC_FUNC_PATH}/include)

add_subdirectory(${LEETCODE_PATH})
add_subdirectory(${PUBLIC_FUNC_PATH})

aux_source_directory(${LEETCODE_PATH}/src/ LEETCODE_SRCS)
aux_source_directory(${PUBLIC_FUNC_PATH}/src PUBLIC_FUNC_SRCS)

add_library(public STATIC ${PUBLIC_FUNC_SRCS})
add_executable(LeetCodePractice main.cpp ${LEETCODE_SRCS})

target_link_libraries(LeetCodePractice ${PROJECT_SOURCE_DIR}/lib/libpublic.a)
