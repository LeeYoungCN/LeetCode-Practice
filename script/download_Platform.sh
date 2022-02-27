#!/bin/bash

git_ssh=""
git_user=""
git_repository=""
git_branch=""
git_zip=""
git_zip_link=""

##### log 打印 #####
function print_log()
{
    d=$(date "+%Y-%m-%d %H:%M:%S")
    echo "${d} ${1}"
}

function result_log()
{
    if [ $1 -eq 0 ]; then
        print_log "$2 success!"
    else
        print_log "$2 fail!"
    fi
}

##### 备份文件处理 #####
function backup_file()
{
    file="${1}"
    if [ -e ${file} ]; then
        mv -f "${file}" "${file}_backup"
        result_log $? "back up ${file}"
    fi
}

function reset_from_backup()
{
    file="${1}"
    if [ -e "${file}_backup" ]; then
        mv -f "${file}_backup" "${file}"
        result_log $? "reset  ${file}_backup -> ${file}"
    fi
}

function delete_backup()
{
    file="${1}"
    if [ -e "${file}_backup" ]; then
        rm -rf "${file}_backup"
        result_log $? "delete  ${file}_backup"
    fi
}

function process_backup()
{
    result=${1}
    folder=${2}
    if [ ${result} -eq 0 ]; then
        delete_backup "${folder}"
    else
        reset_from_backup "${folder}"
    fi
}

function copy_tmplate_file()
{
    file_name="${1}"
    if [ ! -e ${root}/${file_name} ];then
        cp -rf ${template_path}${file_name} ${root}${file_name}
    fi
}

function copy_all_file()
{
    folder=${1}
    for file in $(find ${folder} -type f); do
        file_name=${file##${folder}}
        copy_tmplate_file "${file_name}"
    done
}

##### git 仓处理 #####
function get_git_info()
{
    git_ssh="${1}"
    git_branch="${2}"
    git_user=${git_ssh#git@github.com:}
    git_user=${git_user%/*}
    git_repository=${git_ssh#*/}
    git_repository=${git_repository%*.git}
    git_zip="${git_repository}-${git_branch}.zip"
    git_zip_link="https://github.com/${git_user}/${git_repository}/archive/refs/heads/${git_branch}.zip"
}

function git_clone_repository()
{
    ssh_path="${1}"
    branch="${2}"
    repository=${ssh_path#*/}
    repository=${repository%*.git}
    log_str="git clone ${ssh_path}"
    # 优先git pull
    if [ -e "${repository}" ]; then
        pushd ./${repository} >> /dev/null
        git checkout ${branch}
        git pull
        result=$?
        result_log "${result}" "git pull ${repository}"
        popd >> /dev/null
        if [ ${result} -eq 0 ]; then
            return 0
        fi
    fi
    # git pull 失败则进行git clone
    backup_file "${repository}"
    git clone "${ssh_path}"
    result=$?
    result_log ${result} "${log_str}"
    process_backup ${result} "${repository}"
    if [ ${result} -ne 0 ]; then
        return 1
    fi

    chmod -R 700 ${repository}
    pushd ./${repository}
    git checkout ${branch}
    popd
    return 0
}

function unzip_file()
{
    zip_file=${1}
    unzip_file=${2}
    log_str="unzip ${zip_file}"
    if [ ! -e "${zip_file}" ]; then
        print_log "${zip_file} not exist!"
        return 1
    fi
    if [ -e "${unzip_file}" ]; then
        backup_file "${unzip_file}"
    fi

    unzip -o ${zip_file}
    result=$?
    if [ ${result} -eq 0 ]; then
        mv -f "${zip_file%%.zip}" "${unzip_file}"
        chmod -R 700 "${unzip_file}"
    fi
    result_log      "${result}" "${log_str}"
    process_backup  "${result}" "${unzip_file}"
    return ${result}
}

function download_file()
{
    link="$1"
    target="$2"
    log_str="download ${target}"
    if [ -e ${target} ]; then
        backup_file ${target}
    fi
    wget -O ${target} ${link}
    result=$?
    result_log "${result}" "${log_str}"
    if [ ${result} -ne 0 ]; then
        rm -rf ${target}
        return 1
    fi
    process_backup  "${result}" "${target}"
    return 0
}

function get_platform()
{
    get_git_info "git@github.com:LeeYoungCN/Platform.git" "master"
    git_clone_repository "${git_ssh}" "${git_branch}"
    if [ $? -eq 0 ]; then
        return 0
    fi
    download_file ${git_zip_link} ${git_zip}
    unzip_file "${git_zip}" "${git_repository}"
    if [ $? -ne 0 ] && [ ! -e ${repository} ]; then
        return 1
    fi
    return 0
}

if [ $# -gt 0 ]; then
    if [ -d $1 ]; then
        pushd $1
    else
        cd ..
    fi
else
    cd ..
fi

get_platform
if [ $? -ne 0 ]; then
    exit
fi

root=$(pwd)
platform_path=$(cd Platform;pwd)
template_path="${platform_path}/template"

if [ ! -d ${root}/.vscode ]; then
    mkdir -p ${root}/.vscode
fi

copy_all_file ${template_path}

if [ -e ${root}/script/init_env.sh ]; then
    pushd ${root}/script
else
    pushd ${platform_path}/script
fi

./init_env.sh
