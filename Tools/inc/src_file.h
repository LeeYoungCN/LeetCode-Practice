#ifndef SRC_FILE_H
#define SRC_FILE_H
#include <iostream>
#include <fstream>

using namespace std;

class SrcFile {
public:
    SrcFile(char* name);
    void CreateCPP();
private:
    char* fileName;
    ofstream targetFile;
};

#endif // SRC_FILE_H