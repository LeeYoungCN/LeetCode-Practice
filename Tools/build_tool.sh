#!/bin/bash
source ../script/public_config.sh

rm -rf ./build

for path in $*; do
    if [ -d ./${path} ]; then
        cmake_command="cmake -S . -B ./build -DTARGET_PATH=$path -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchain.cmake"
        if [ "${system}" = "Windows" ]; then
            ${cmake_command} -G "MinGW Makefiles"
        else
            ${cmake_command}
        fi
    fi
done

cmake --build build --target all
