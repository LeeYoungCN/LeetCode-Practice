#!/bin/bash
file=$1
path=$2
def_str=""
created_date=""
head_format="*.h"
cd $path

function CreateFile()
{
    if [ -e ${file} ];then
        rm -rf ${file}
    fi
    touch ${file}
}

function GetDefStr()
{
    def_str=${file/./_}
    def_str=$(echo ${def_str} | tr [:lower:] [:upper:])
}

function GetCreateDate()
{
    tmp=$(date)
    tmp=${tmp/ /0}
    year=${tmp:0:4}
    mon=${tmp:5:2}
    day=${tmp:8:2}
    hour=${tmp:16:2}
    minu=${tmp:19:2}
    sec=${tmp:22:2}
    created_date="${year}-${mon}-${day} ${hour}:${minu}:${sec}"
}

function Init()
{
    GetDefStr
    GetCreateDate
    CreateFile
}

function WriteData()
{
    echo -e "$*" >> ${file}
}

function WriteOneFileHead()
{
    key=${1}
    value=${2}
    max_len=16
    info_head="\\x20*\\x20"
    space="\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20\\x20"
    space_num=`expr ${max_len} - ${#key} - 3`
    if [ "${key}" == "Title" ]; then
        info="${info_head}${value}"
    else
        info="${info_head}${key}${space:0:$[space_num*4]}:\\x20${value}"
    fi
    WriteData ${info}
}

function WriteFileHead()
{
    WriteData '/*'
    WriteOneFileHead "Title"        "LeetCode算法练习"
    WriteOneFileHead "Description"  "LeetCode汇总头文件"
    WriteOneFileHead "Author"       "李阳"
    WriteOneFileHead "Created"      "${created_date}"
    WriteData ' */'
    WriteData
}

function WriteOneMacDef()
{
    key=${1}
    value=${2}
    info="#${key} ${value}"
    WriteData ${info}
}

function WriteStartMacDef()
{
    WriteOneMacDef "ifndef" "${def_str}"
    WriteOneMacDef "define" "${def_str}"
    WriteData
}

function WriteEndMacDef()
{
    WriteOneMacDef "endif" "// ${def_str}"
}

function WriteOneIncLibFile()
{
    info="#include <$1>"
    WriteData ${info}
}

function WriteOneIncUserFile()
{
    info="#include \"$1\""
    WriteData ${info}
}

function WriteAllIncUserFile()
{
    for file_name in ${head_format}; do
        if [ -e ${file_name} -a "${file_name}" != "${file}" ]; then
            WriteOneIncUserFile ${file_name}
        fi
    done
    WriteData
}

Init
WriteFileHead
WriteStartMacDef
WriteAllIncUserFile
WriteEndMacDef
