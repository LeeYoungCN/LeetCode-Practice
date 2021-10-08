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
    OpenFile();
    WriteFileHead();
    WriteIncFiles();
    WriteNamespaces();
    WriteFunctions();
}

void SrcFile::CreateIncFile()
{
    string incFileFullName = filePath + incFileName;
    IncFile incFile(incFileFullName);
    incFile.SetFileHead(fileHead);
    incFile.SetFunction(functions);
    incFile.CreateFile();
}

void SrcFile::AddSameIncFile()
{
    AddUserFile(incFileName);
}

string SrcFile::GetIncFileName()
{
    if (incFileName.size() == 0) {
        string incSuffix = ".h";
        incFileName = string(fileName, 0, fileName.size() - suffix.size()) + incSuffix;
    }
    return incFileName;
}

void SrcFile::Init() {
    suffix = ".cpp";
    InitNameInfo();
    GetIncFileName();
}

void SrcFile::WriteFunctions()
{
    for (auto& [name, content] : functions)
    {
        file << name << endl;
        file << "{" << endl;
        for (const string& line : content) {
            file << "    " << line << ";" << endl;
        }
        file << "}" << endl;
        file << endl;
    }
}
