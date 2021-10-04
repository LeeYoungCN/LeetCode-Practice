/*
 * 代码文件类
 * Description  : 代码文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */
#ifndef CODE_FILE_H
#define CODE_FILE_H
#include <iostream>
#include <regex>
#include <fstream>
#include <ctime>
using namespace std;

class CodeFile {
public:
    CodeFile(string f);
    CodeFile(const char* f);
    ~CodeFile();
    virtual void Init() = 0;
    virtual void CreateFile() = 0;
    virtual string GetFileName();
    virtual void SetLibFile(vector<string> fles);
    virtual void SetUserFile(vector<string> files);
    virtual void SetFileHead(vector<pair<string, string> > head);
    virtual void SetHeadValue(string key, string value);
    
protected:
    virtual void OpenFile();
    virtual void WriteIncFiles();
    virtual void WriteNamespaces();

    virtual void WriteLibFile(string head);
    virtual void WriteUserFile(string head);
    virtual void WriteMacDef(string key, string value);
    virtual void WriteNamespace(string space);
    virtual void WriteFileHead();
    virtual void WriteOneFileHead(string key, string value);
    virtual string GetDate();

    string fullFile;
    string fileName;
    ofstream file;
    vector<string> libFiles = {};
    vector<string> userFiles = {};
    vector<string> nsVec = {"std"};
    vector< pair<string, string> > fileHead = {
        {"title", ""}, {"Description", ""}, {"Author", "李阳"}, {"Date", ""},
    };
};
#endif // CODE_FILE_H