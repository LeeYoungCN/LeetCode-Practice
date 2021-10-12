set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

set(TARGET_NAME LeetCodePractice)
set(GTEST_LIB ${GOOGLE_TEST_PATH}/lib)
include_directories(${GOOGLE_TEST_PATH}/inc)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CODE_SRCS)

add_executable(${TARGET_NAME})

target_sources(${TARGET_NAME} PRIVATE ${CODE_SRCS})
#add_subdirectory((${PUBLIC_FUNC_PATH}))
#add_subdirectory(public_function)

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows*")
    target_link_libraries(${TARGET_NAME} ${GTEST_LIB}/libgtest.a ${GTEST_LIB}/libgmock.a)
else()
    target_link_libraries(${TARGET_NAME} ${GTEST_LIB}/libgtestd.a ${GTEST_LIB}/libgmockd.a)
endif()
