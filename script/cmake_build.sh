#!/bin/bash
./cmake_clean.sh
source ./public_config.sh

cd ..
cmake_command='cmake -S . -B ./build -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain.cmake'

if [ "${system}" = "Windows" ]; then
     cmake_command=`${cmake_command} -G "MinGW Makefiles"`
fi
echo "${cmake_command}"
${cmake_command}
cmake --build build --target public
cmake --build build --target LeetCodePractice
cmake --build build --target create_CPP
