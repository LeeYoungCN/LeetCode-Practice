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
#include <set>
#include <vector>

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
    virtual void SetLibFile(set<string> fles);
    virtual void AddLibFile(string newFile);
    virtual void SetUserFile(vector<string> files);
    virtual void SetUserFile(set<string> files);
    virtual void AddUserFile(string newFile);
    virtual void SetFileHead(vector<pair<string, string> > head);
    virtual void SetHeadValue(string key, string value);
    virtual void AddHeadValue(string key, string value);

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
    string suffix = "*";
    set<string> libFiles = {};
    set<string> userFiles = {};
    set<string> nsVec = {"std"};
    vector< pair<string, string> > fileHead = {
        {"Title", ""}, {"Description", ""}, {"Author", "李阳"}, {"Created", ""},
    };
};

#endif // CODE_FILE_H