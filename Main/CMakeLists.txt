set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(TARGET_NAME LeetCodePractice)
set(GTEST_LIB_PATH ${GOOGLE_TEST_PATH}/lib)
include_directories(${GOOGLE_TEST_PATH}/inc)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CODE_SRCS)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE ${CODE_SRCS})

file(GLOB GTEST_LIBS ${GTEST_LIB_PATH}/*.a)

target_link_libraries(${TARGET_NAME} ${GTEST_LIBS} pthread)

