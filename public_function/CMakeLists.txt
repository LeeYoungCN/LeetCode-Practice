aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src PUBLIC_FUNC_SRCS)

target_include_directories(${LIB_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_sources(${LIB_NAME} PRIVATE ${PUBLIC_FUNC_SRCS})
