/*
 * CPP文件类
 * Description  : 创建cpp文件
 * Author       : 李阳
 * Created      : 2021-08-16
 */
#ifndef CPP_FILE_H
#define CPP_FILE_H
#include <iostream>
#include <fstream>

using namespace std;

class CppFile {
public:
    CppFile(char* name);
    ~CppFile();
    void CreateCPP();
private:
    char* fileName;
    ofstream targetFile;
};

#endif // CPP_FILE_H