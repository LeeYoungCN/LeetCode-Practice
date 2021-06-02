include_directories(${PUBLIC_FUNC_PATH}/include)
aux_source_directory(${PUBLIC_FUNC_PATH}/src PUBLIC_FUNC_SRCS)
add_library(public STATIC ${PUBLIC_FUNC_SRCS})
