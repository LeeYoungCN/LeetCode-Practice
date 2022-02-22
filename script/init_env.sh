#!/bin/bash

cd ..
root_path=$(pwd)

if [ ! -e Platform ];then
    ./download_Platform.sh
    if [ $? -ne 0 ]; then
        exit
    fi
fi

cd ${root_path}/Platform/script/
./init_env.sh

cd ${root_path}/Tools/
./build_tool.sh code_file leetcode_file