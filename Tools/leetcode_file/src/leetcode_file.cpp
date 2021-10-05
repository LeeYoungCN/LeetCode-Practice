/*
 * LeetCode练习文件
 * Description  : LeetCode练习文件
 * Author       : 李阳
 * Created      : 2021-10-04
 */

#include "leetcode_file.h"
#include "inc_file.h"
#include "src_file.h"

LeetCodeFile::LeetCodeFile(char* num, char* adress) : probNum(num), netAdress(adress){
    Init();
}

LeetCodeFile::~LeetCodeFile() {}

void LeetCodeFile::CreateFile()
{
    string description = "LeetCode题库" + probNum + "题, " + netAdress;
    SrcFile src_file(fileName);
    src_file.AddUserFile("public_function.h");
    src_file.SetHeadValue("Title", "LeetCode算法练习");
    src_file.SetHeadValue("Description", description);
    src_file.CreateFile();
    src_file.CreateIncFile();
}

void LeetCodeFile::Init()
{
    int start = netAdress.find("problems") + sizeof("problems");
    int end   = netAdress.find('/', start);
    fileName += string(4 - probNum.size(), '0') + probNum;
    fileName += '_';
    for (int i = start; i < end; i++) {
        fileName.push_back(netAdress[i] == '-'? '_': netAdress[i]);
    }
}