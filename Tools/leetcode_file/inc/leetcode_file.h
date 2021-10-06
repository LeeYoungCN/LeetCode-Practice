/*
 * LeetCode练习文件
 * Description  : LeetCode练习文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */
#ifndef LEETCODE_FILE_H
#define LEETCODE_FILE_H

#include <iostream>
#include <set>

using namespace std;

class LeetCodeFile {
public:
    LeetCodeFile(char* num, char* adress);
    ~LeetCodeFile();
    void CreateFile();
private:
    void CreateCodeFile();
    void CreateMainFile();
    void Init();
    string probNum;
    string netAdress;
    string fileName = "lc";
    set<string> libFiles = {
        "iostream", "algorithm",    "climits",  "numeric",  "vector",
        "deque",    "list",         "set",      "map",      "unordered_set",
        "unordered_map"
    };
};

#endif // LEETCODE_FILE_H