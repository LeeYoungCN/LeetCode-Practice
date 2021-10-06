target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.a)