aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src LEETCODE_SRCS)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${TARGET_NAME} PRIVATE ${LEETCODE_SRCS})