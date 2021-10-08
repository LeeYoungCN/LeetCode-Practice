#!/bin/bash
source ../script/public_config.sh
cmake_tool=${root_path}/cmake/toolchain.cmake

rm -rf ./build

for path in $*; do
    if [ -d ./${path} ]; then
        cmake_command="cmake -S . -B ./build -DTARGET_PATH=$path -DCMAKE_TOOLCHAIN_FILE=${cmake_tool}"
        if [ "${system}" = "Windows" ]; then
            ${cmake_command} -G "MinGW Makefiles"
        else
            ${cmake_command}
        fi
        cmake --build build --target all
    fi
done
