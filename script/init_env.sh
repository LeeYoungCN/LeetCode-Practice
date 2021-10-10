#!/bin/bash
cfg_file=public_config.sh

if [ -e ${cfg_file} ];then
    rm ${cfg_file}
fi

touch ${cfg_file}
chmod 777 ${cfg_file}

function write_cfg()
{
    (echo "${1}")>>${cfg_file}
}
pushd ..
root_path=$(pwd)
popd
system="${1}"

write_cfg "system=${system}"
write_cfg "root_path=${root_path}"

cd ..
workspace=$(pwd)
cd ./platform/${system}
cp -rf .vscode ${workspace}
cp -rf * ${workspace}

cd ${root_path}/Tools/
./build_tool.sh code_file leetcode_file