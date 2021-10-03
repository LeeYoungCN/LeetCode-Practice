#!/bin/bash
source ./public_config.sh
target_path=${root_path}/LeetCode
cpp_path=${target_path}/src
head_path=${target_path}/inc
cpp_format="../*.cpp"
head_format="../*.h"

function move() {
for full_file in ${1}
do
    file_name=${full_file#*/}
    if [ "${file_name}" != "main.cpp" ]; then
        cp -rf ${full_file} ${2}/${file_name}
        rm -rf ${full_file}
        echo "move $file_name sucess!"
    fi
done
}

move ${cpp_format}  ${cpp_path}
move ${head_format} ${head_path}
