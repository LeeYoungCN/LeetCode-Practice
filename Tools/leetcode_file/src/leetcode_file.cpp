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
    CreateCodeFile();
    CreateMainFile();
}

void LeetCodeFile::CreateCodeFile()
{
    string description = "LeetCode题库" + probNum + "题, " + netAdress;
    SrcFile src_file(fileName);
    src_file.SetLibFile(libFiles);
    src_file.AddUserFile("public_function.h");
    src_file.AddSameIncFile();
    src_file.SetHeadValue("Title", "LeetCode算法练习");
    src_file.SetHeadValue("Description", description);
    src_file.CreateFile();
    src_file.CreateIncFile();
    src_file.CreateTestFile();
}

void LeetCodeFile::CreateMainFile()
{
    string mainName = "main.cpp";
    SrcFile src_file(mainName);
    src_file.SetHeadValue("Title", "LeetCode算法练习");
    src_file.CreateFile();
}

void CreateTestFile()
{
    ;
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