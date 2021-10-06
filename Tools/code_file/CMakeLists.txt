set(TARGET_NAME CodeFile)
add_library(${TARGET_NAME} STATIC)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src CODE_SRCS)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${TARGET_NAME} PRIVATE ${CODE_SRCS})
