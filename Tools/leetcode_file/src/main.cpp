#include <iostream>
#include "leetcode_file.h"

using namespace std;

int main(int argc, char* argv[]) 
{
    LeetCodeFile f(argv[1], argv[2]);
    f.CreateFile();
    return 0;
}
