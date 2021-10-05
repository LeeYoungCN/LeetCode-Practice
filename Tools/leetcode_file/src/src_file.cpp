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

void SrcFile::CreateFile()
{
    WriteFileHead();
    WriteIncFiles();
    WriteUserFile(headFileName);
    WriteNamespaces();
}

void SrcFile::Init() {
    if (!regex_match(fullFile, pattern)) {
        fullFile += ".cpp";
    }
    SetLibFile(this->libFiles);
    fileName = GetFileName();
    headFileName = string(fileName, 0, fileName.size() - 3) + "h";
    OpenFile();
}

void SrcFile::CreateIncFile()
{
    string inc_file_name = string(fullFile, 0, fullFile.size() - 3) + "h";
    IncFile inc_file(inc_file_name);
    inc_file.SetFileHead(CodeFile::fileHead);
    inc_file.CreateFile();
}