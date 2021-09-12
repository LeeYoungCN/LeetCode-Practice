#!/bin/bash
./cmake_clean.sh
source ./public_config.sh

cd ..
cmake_command='cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain.cmake'

if [ "${system}" = "Windows" ]; then
     ${cmake_command} -G "MinGW Makefiles"
else
     ${cmake_command}
fi

cmake --build build --target public
cmake --build build --target LeetCodePractice
