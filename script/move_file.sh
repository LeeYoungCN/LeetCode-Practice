#!/bin/bash
source ./public_config.sh
target_path=${root_path}/LeetCode
cpp_path=${target_path}/src
head_path=${target_path}/inc
cpp_format="*.cpp"
head_format="*.h"
pushd ${root_path}

function move() {
    for full_file in ${1}
    do
        file_name=${full_file#*/}
        if [ -e ${file_name}  -a "${file_name}" != "main.cpp" ]; then
            cp -rf ${full_file} ${2}
            rm -rf ${full_file}
            echo "move $full_file sucess!"
        fi
    done
}

move ${cpp_format}  ${cpp_path}
move ${head_format} ${head_path}

popd
./create_all_inc.sh leetcode_head.h ${head_path}