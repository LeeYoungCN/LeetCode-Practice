/*
 * 源文件类
 * Description  : 创建源文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */
#include "src_file.h"

SrcFile::SrcFile(string f) : CodeFile(f) {
    Init();
}

SrcFile::SrcFile(const char* f) : CodeFile(f) {
    Init();
}

SrcFile::~SrcFile()
{
    file.close();
}

void SrcFile::CreateFile()
{
    WriteIncFiles();
    WriteUserFile(headFileName);
    WriteNamespaces();
    
}

void SrcFile::Init() {
    if (!regex_match(fullFile, pattern)) {
        fullFile += ".cpp";
    }
    CodeFile::SetLibFile(this->libFiles);
    CodeFile::SetUserFile(this->userFiles);
    fileName = GetFileName();
    headFileName = string(fileName, 0, fileName.size() - 3) + "h";
    file.open(fullFile.c_str(), ios::app | ios::in);
}
