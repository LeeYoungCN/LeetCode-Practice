aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src PUBLIC_FUNC_SRCS)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${TARGET_NAME} PRIVATE ${PUBLIC_FUNC_SRCS})
