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
    void AddSameIncFile();
    string GetIncFileName();
private:
    void Init() override;
    void WriteFunctions() override;

    string incFileName = "";
};

#endif // INC_FILE_H