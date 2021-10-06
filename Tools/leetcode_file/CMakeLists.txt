set(TARGET_NAME CreateFile)
set(LIB_FILE ${LIBRARY_OUTPUT_PATH}/libCodeFile.a)
set(LIB_INC_PATH ${TOOLS_ROOT_PATH}/code_file/inc)

add_executable(${TARGET_NAME})

include_directories(${LIB_INC_PATH})
target_link_libraries(${TARGET_NAME} ${LIB_FILE})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src CODE_SRCS)
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_sources(${TARGET_NAME} PRIVATE ${CODE_SRCS})
