/*
 * 代码文件类
 * Description  : 代码文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */

#include "code_file.h"

/******public******/
CodeFile::CodeFile(string f) : fullFile(f) {};

CodeFile::CodeFile(const char* f) : fullFile(string(f)) {};

CodeFile::~CodeFile()
{
    file.close();
}

string CodeFile::GetFileName()
{
    if (fileName.size()) {
        return fileName;
    }
    int pos = 0;
    int len = fullFile.size();
    while (pos < len && fullFile.find('/', pos) != string::npos) {
        pos = fullFile.find('/', pos) + 1;
    }
    return string(fullFile, pos, len);
}

void CodeFile::SetLibFile(vector<string> files)
{
    libFiles = files;
}

void CodeFile::SetUserFile(vector<string> files)
{
    userFiles = files;
}

void CodeFile::SetFileHead(vector<pair<string, string> > head)
{
    fileHead = head;
}

void CodeFile::SetHeadValue(string key, string value)
{
    for (pair<string, string>& p : fileHead) {
        if (key == p.first) {
            p.second = value;
        }
    }
}

/******protected******/
void CodeFile::OpenFile()
{
    file.open(fullFile.c_str(), ios::app | ios::in);
}

void CodeFile::WriteIncFiles()
{
    for (string& libFile : this->libFiles) {
        WriteLibFile(libFile);
    }
    file << endl;
    for(string& userFile : userFiles) {
        WriteUserFile(userFile);
    }
}

void CodeFile::WriteNamespaces()
{
    for(string& space : nsVec) {
        WriteNamespace(space);
    }
}

void CodeFile::WriteLibFile(string head)
{
    file << "#include <" << head << ">" << endl;
}

void CodeFile::WriteUserFile(string head)
{
    file << "#include \"" << head << "\"" << endl;
}

void CodeFile::WriteMacDef(string key, string value)
{
    file << "#" << key << " " << value << endl;
}

void CodeFile::WriteNamespace(string space)
{
    file << "using namespace " << space << ";" << endl;
}

void CodeFile::WriteFileHead()
{
    file << "/*" << endl;
    for (pair<string, string>& p : fileHead) {
        WriteOneFileHead(p.first, p.second);
    }
    file << " */" << endl;
}

void CodeFile::WriteOneFileHead(string key, string value)
{
    const string startStr = " * ";
    const int N = 16;
    file << startStr ;
    if (key != "Title") {
        file << key << string(N - key.size() - startStr.size(), ' ') << " : ";
    }
    if (key == "Created") {
        value = GetDate();
    }
    file << value << endl;
}

string CodeFile::GetDate()
{
    string timeStr;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    auto toStr = [](int time_data, string symbol) -> string {
        string ret;
        if (time_data < 10) {
            ret += "0";
        }
        ret += to_string(time_data) + symbol;
        return ret;
    };
    timeStr += toStr(1900 + ltm->tm_year, "-");
    timeStr += toStr(ltm->tm_mon + 1,  "-");
    timeStr += toStr(ltm->tm_mday, " ");
    timeStr += toStr(ltm->tm_hour, ":");
    timeStr += toStr(ltm->tm_min,  ":");
    timeStr += toStr(ltm->tm_sec,  "");
    return timeStr;
}
