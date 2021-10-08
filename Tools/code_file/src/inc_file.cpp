/*
 * 头文件类
 * Description  : 创建头文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */

#include "inc_file.h"

IncFile::IncFile(string f) : CodeFile(f) {
    Init();
}

IncFile::IncFile(const char* f) : CodeFile(f) {
    Init();
}

IncFile::~IncFile() {}

void IncFile::CreateFile()
{
    OpenFile();
    WriteFileHead();
    string defStr = GetDefStr();
    WriteMacDef("ifndef", defStr);
    WriteMacDef("define", defStr);
    file << endl;
    WriteIncFiles();
    WriteFunctions();
    WriteMacDef("endif //", defStr);
}

void IncFile::Init() {
    suffix = ".h";
    InitNameInfo();
}

void IncFile::WriteFunctions()
{
    for (auto& [name, content] : functions)
    {
        file << name << ";" << endl;
    }
    if (!functions.empty()) {
        file << endl;
    }
}

string IncFile::GetDefStr()
{
    string ret = "";
    for (char& chr : fileName) {
        char c = chr;
        if (c == '.') {
            c = '_';
        } else if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        ret.push_back(c);
    }
    return ret;
}
