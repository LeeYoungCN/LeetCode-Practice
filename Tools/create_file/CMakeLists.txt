set(TARGET_NAME CreateFile)
add_executable(${TARGET_NAME})
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src CODE_SRCS)

target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${TARGET_NAME} PRIVATE ${CODE_SRCS})