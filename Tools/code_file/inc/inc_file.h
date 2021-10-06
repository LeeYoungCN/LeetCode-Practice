/*
 * 头文件类
 * Description  : 创建头文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */
#ifndef INC_FILE_H
#define INC_FILE_H

#include <iostream>
#include <regex>
#include <fstream>
#include "code_file.h"

using namespace std;

class IncFile : public CodeFile{
public:
    IncFile(string fileName);
    IncFile(const char* fileName);
    ~IncFile();
    void CreateFile()override;
private:
    void Init() override;
    string GetDefStr();
};

#endif // INC_FILE_H