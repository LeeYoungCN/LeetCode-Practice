/*
 * 源文件类
 * Description  : 创建源文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */
#ifndef SRC_FILE_H
#define SRC_FILE_H

#include <iostream>
#include <regex>
#include <fstream>
#include "code_file.h"

using namespace std;

class SrcFile : public CodeFile {
public:
    SrcFile(string fileName);
    SrcFile(const char* fileName);
    ~SrcFile();
    void CreateFile() override;
    void InsertHeadFile();
    void CreateIncFile();
private:
    void Init() override;
    void GetDefStr();

    string headFileName;
    regex pattern{".*.cpp$"};
    vector<string> libFiles = {
        "iostream", "algorithm",    "climits",  "numeric",  "vector",
        "deque",    "list",         "set",      "map",      "unordered_set",
        "unordered_map"
    };
};

#endif // INC_FILE_H