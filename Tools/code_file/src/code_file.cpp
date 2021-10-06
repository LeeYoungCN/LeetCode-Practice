/*
 * 代码文件类
 * Description  : 代码文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */

#include "code_file.h"

/********************public********************/
CodeFile::CodeFile(string f) : fullFile(f) {};

CodeFile::CodeFile(const char* f) : fullFile(string(f)) {};

CodeFile::~CodeFile()
{
    file.close();
}

string CodeFile::GetFileName()
{
    return fileName;
}

/********************编辑库文件********************/
void CodeFile::SetLibFile(vector<string> files)
{
    libFiles = set<string>(files.begin(), files.end());
}

void CodeFile::SetLibFile(set<string> files)
{
    libFiles = files;
}

void CodeFile::AddLibFile(string newFile)
{
    if (libFiles.count(newFile)) {
        return;
    }
    libFiles.insert(newFile);
}

/********************编辑用户头文件********************/
void CodeFile::SetUserFile(vector<string> files)
{
    userFiles = set<string>(files.begin(), files.end());
}

void CodeFile::SetUserFile(set<string> files)
{
    userFiles = files;
}

void CodeFile::AddUserFile(string newFile)
{
    if (userFiles.count(newFile)) {
        return;
    }
    userFiles.insert(newFile);
}

/********************编辑用户头文件********************/
void CodeFile::SetNameSpaces(vector<string> spaces)
{
    nameSpaces = set<string>(spaces.begin(), spaces.end());
}

void CodeFile::SetNameSpaces(set<string> spaces)
{
    nameSpaces = spaces;
}

void CodeFile::AddNameSpace(string space)
{
    if (nameSpaces.count(space)) {
        return;
    }
    nameSpaces.insert(space);
}

/********************编辑文件头********************/
void CodeFile::SetFileHead(vector<pair<string, string> > head)
{
    fileHead = head;
}

void CodeFile::SetHeadValue(string key, string value)
{
    bool flag = false;
    for (pair<string, string>& p : fileHead) {
        if (key == p.first) {
            p.second = value;
            flag = true;
            break;
        }
    }
    if (!flag) {
        fileHead.emplace_back(make_pair(key, value));
    }
}

void CodeFile::AddHeadValue(string key, string value)
{
    SetHeadValue(key, value);
}

/********************protected********************/
void CodeFile::InitNameInfo()
{
    string patternStr = ".*" + suffix + "$";
    regex pattern{patternStr};
    if (!regex_match(fullFile, pattern)) {
        fullFile += suffix;
    }
    int pos = 0;
    int len = fullFile.size();
    while (pos < len && fullFile.find('/', pos) != string::npos) {
        pos = fullFile.find('/', pos) + 1;
    }
    fileName = string(fullFile, pos, len);
    filePath = string(fullFile, 0, fullFile.size() - fileName.size());
}

void CodeFile::OpenFile()
{
    file.open(fullFile.c_str(), ios::app | ios::in);
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

void CodeFile::WriteFileHead()
{
    file << "/*" << endl;
    for (pair<string, string>& p : fileHead) {
        WriteOneFileHead(p.first, p.second);
    }
    file << " */" << endl;
    file << endl;
}

void CodeFile::WriteIncFiles()
{
    for (const string& libFile : this->libFiles) {
        WriteLibFile(libFile);
    }
    file << endl;
    for(const string& userFile : userFiles) {
        WriteUserFile(userFile);
    }
    file << endl;
}

void CodeFile::WriteNamespaces()
{
    for(const string& space : nameSpaces) {
        WriteOneNameSpace(space);
    }
    file << endl;
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

void CodeFile::WriteOneNameSpace(string space)
{
    file << "using namespace " << space << ";" << endl;
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
