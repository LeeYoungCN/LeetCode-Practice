#!/bin/bash
source ./public_config.sh
target_path=${root_path}/LeetCode
cpp_path=${target_path}/src
head_path=${target_path}/inc
cpp_format="*.cpp"
head_format="*.h"
pushd ${root_path}/Main/

if [ -e main.cpp ]; then
    rm -rf main.cpp
fi

function move() {
    path=${2}
    for file_name in ${1}
    do
        if [ -e ${file_name} ]; then
            cp -rf ${file_name} ${path}
            rm -rf ${file_name}
            echo "move $file_name sucess!"
        fi
    done
}

move "${cpp_format}"  "${cpp_path}"
move "${head_format}" "${head_path}"

popd
./create_all_inc.sh "leetcode_head.h" ${head_path}