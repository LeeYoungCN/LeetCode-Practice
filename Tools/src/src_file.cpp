#include <iostream>
#include "src_file.h"
using namespace std;

SrcFile::SrcFile(char* name):fileName(name)
{
    targetFile.open(name, ios::app);
    cout << fileName << endl;
    targetFile<<"456";
    targetFile.close();
}
