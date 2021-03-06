#!/bin/bash
source ../Platform/script/public_config.sh
cmake_tool=${cmake_source_dir}/cmake/toolchain.cmake

rm -rf ./build

for path in $*; do
    if [ -d ./${path} ]; then
        cmake_command="cmake -S . -B ./build -DTARGET_PATH=$path"
        if [ "${os}" = "Windows" ]; then
            ${cmake_command} -G "MinGW Makefiles"
        else
            ${cmake_command}
        fi
        cmake --build build --target all
    fi
done
