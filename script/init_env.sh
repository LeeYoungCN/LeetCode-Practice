#!/bin/bash
cfg_file=public_config.sh

if [ -e ${cfg_file} ];then
    rm ${cfg_file}
fi

touch ${cfg_file}
chmod 777 ${cfg_file}

function CreateCfg()
{
    (echo "${1}")>>${cfg_file}
}

system="${1}"

CreateCfg "system=${system}"

cd ..
workspace=$(pwd)
cd ./platform/${system}
cp -rf .vscode ${workspace}
cp -rf * ${workspace}
