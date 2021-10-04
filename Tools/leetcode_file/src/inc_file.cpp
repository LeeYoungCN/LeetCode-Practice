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

IncFile::~IncFile()
{
    file.close();
}

void IncFile::CreateFile()
{
    WriteFileHead();
    WriteMacDef("ifndef", defStr);
    WriteMacDef("define", defStr);
    WriteIncFiles();
    WriteNamespaces();
    file << endl;
    WriteMacDef("endif //", defStr);
}

void IncFile::Init() {
    if (!regex_match(fullFile, pattern)) {
        fullFile += ".h";
    }
    fileName = GetFileName();
    defStr = GetDefStr();
    OpenFile();
}

string IncFile::GetDefStr()
{
    string ret = "";
    for (auto& chr : fileName) {
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
