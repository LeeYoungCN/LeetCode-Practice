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
    if (file) {
        file.close();
    }
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
    for (auto& p : fileHead) {
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
