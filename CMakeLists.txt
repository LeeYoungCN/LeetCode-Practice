project(MiniProject)
cmake_minimum_required(VERSION 3.4.1)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
set(TARGET_NAME LeetCodePractice)

set(CODE_PATH               ${CMAKE_SOURCE_DIR}/Main)
set(BUILDCACHE_PATH         ${CMAKE_SOURCE_DIR}/buildcache)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_SOURCE_DIR}/lib)

set(PLATFORM_PATH            ${CMAKE_SOURCE_DIR}/Platform)
set(PLATFORM_INC_PUBLIC_PATH ${PLATFORM_PATH}/inc/public_func)
set(PLATFORM_INC_GTEST_PATH  ${PLATFORM_PATH}/inc/google_test)
set(PLATFORM_LIBRARY_PATH    ${PLATFORM_PATH}/lib)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS   "-Wall -g")
set(CMAKE_CXX_FLAGS "-Wall -g")

include_directories(${PLATFORM_INC_PUBLIC_PATH})
include_directories(${PLATFORM_INC_GTEST_PATH})

add_executable(${TARGET_NAME})
add_subdirectory(${CODE_PATH})

file(GLOB PLATFORM_LIBS ${PLATFORM_LIBRARY_PATH}/*.a)

target_link_libraries(${TARGET_NAME} ${PLATFORM_LIBS} pthread)
