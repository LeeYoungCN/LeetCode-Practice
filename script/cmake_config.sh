#!/bin/bash
./cmake_clean.sh

cd ..
cmake_command='cmake -S . -B ./build'

if [ "${1}" = "Windows" ]; then
     cmake_command=`${cmake_command} -DCMAKE_TOOLCHAIN_FILE=./cmake/win_toolchain.cmake -G "MinGW Makefiles"`
fi
echo "${cmake_command}"
${cmake_command}
