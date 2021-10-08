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
    /*编辑库文件*/
    virtual void SetLibFile(vector<string> fles);
    virtual void SetLibFile(set<string> fles);
    virtual void AddLibFile(string newFile);
    /*编辑用户头文件*/
    virtual void SetUserFile(vector<string> files);
    virtual void SetUserFile(set<string> files);
    virtual void AddUserFile(string newFile);
    /*编辑命名空间*/
    virtual void SetNameSpaces(vector<string> spaces);
    virtual void SetNameSpaces(set<string> spaces);
    virtual void AddNameSpace(string spaces);
    /*编辑文件头*/
    virtual void SetFileHead(vector<pair<string, string> > head);
    virtual void SetHeadValue(string key, string value);
    virtual void AddHeadValue(string key, string value);
    /*编辑函数*/
    virtual void SetFunction(vector<pair<string, vector<string>>> functions);
    virtual void AddFunction(string funcName, vector<string> funcContent);
    /*编辑内容*/
    virtual void SetLine(vector<string> lines);
    virtual void AddLine(string line);

protected:
    virtual void InitNameInfo();
    virtual void OpenFile();
    virtual string GetDate();

    virtual void WriteFileHead();
    virtual void WriteIncFiles();
    virtual void WriteNamespaces();
    virtual void WriteFunctions() = 0;
    virtual void WriteLines();

    virtual void WriteLibFile(string head);
    virtual void WriteUserFile(string head);
    virtual void WriteMacDef(string key, string value);
    virtual void WriteOneNameSpace(string space);
    virtual void WriteOneFileHead(string key, string value);

    string fullFile;
    string fileName;
    string filePath;
    ofstream file;
    string suffix = "";
    set<string> libFiles = {};
    set<string> userFiles = {};
    set<string> nameSpaces = {};
    vector< pair<string, string> > fileHead = {
        {"Title", ""}, {"Description", ""}, {"Author", "李阳"}, {"Created", ""},
    };
    vector<pair<string, vector<string>>> functions = {};
    vector<string> lines = {};
};

#endif // CODE_FILE_H