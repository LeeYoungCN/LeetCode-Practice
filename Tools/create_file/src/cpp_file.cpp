/*
 * CPP文件类
 * Description  : 创建cpp文件
 * Author       : 李阳
 * Created      : 2021-08-16
 */
#include <iostream>
#include "cpp_file.h"
using namespace std;

CppFile::CppFile(char* name):fileName(name)
{
    targetFile.open(name, ios::app);
}

CppFile::~CppFile()
{
    targetFile.close();
}

void CreateFile()
{
    ;
}