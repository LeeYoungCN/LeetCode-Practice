
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src TOOL_SRCS)

target_include_directories(${TOOL_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${TOOL_NAME} PRIVATE ${TOOL_SRCS})