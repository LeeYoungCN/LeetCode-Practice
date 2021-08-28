#!/bin/bash

cd ..
function CleanFolder()
{
    if [ -e ${1} ];then
        rm -rf ${1}
    fi
    mkdir ${1}
}
CleanFolder build
CleanFolder bin
