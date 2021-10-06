/*
 * 源文件类
 * Description  : 创建源文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */

#include "src_file.h"
#include "inc_file.h"

SrcFile::SrcFile(string f) : CodeFile(f) {
    Init();
}

SrcFile::SrcFile(const char* f) : CodeFile(f) {
    Init();
}

SrcFile::~SrcFile() {}

void SrcFile::Init() {
    SetLibFile(this->libFiles);
    suffix = ".cpp";
    string incSuffix = ".h";
    fileName = GetFileName();
    incFileName = string(fileName, 0, fileName.size() - suffix.size()) + incSuffix;
    AddUserFile(incFileName);
    OpenFile();
}

void SrcFile::CreateFile()
{
    WriteFileHead();
    WriteIncFiles();
    WriteNamespaces();
}

void SrcFile::CreateIncFile()
{
    string incFileFullName = string(fullFile, 0, fullFile.size() - suffix.size());
    IncFile incFile(incFileFullName);
    incFile.SetFileHead(CodeFile::fileHead);
    incFile.CreateFile();
}
