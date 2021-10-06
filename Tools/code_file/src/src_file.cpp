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
    suffix = ".cpp";
    InitNameInfo();
    GetIncFileName();
}

void SrcFile::CreateFile()
{
    OpenFile();
    WriteFileHead();
    WriteIncFiles();
    WriteNamespaces();
}

void SrcFile::CreateIncFile()
{
    string incFileFullName = filePath + incFileName;
    IncFile incFile(incFileFullName);
    incFile.SetFileHead(fileHead);
    incFile.CreateFile();
}

void SrcFile::CreateTestFile()
{
    string testFileFullName = filePath + "test_" + fileName;
    SrcFile srcFile(testFileFullName);
    srcFile.SetFileHead(fileHead);
    srcFile.AddUserFile(incFileName);
    srcFile.AddUserFile("gtest/gtest.h");
    srcFile.CreateFile();
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
