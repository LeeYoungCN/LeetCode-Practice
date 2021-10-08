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
    
    vector<string> funcContent = {
        "printf(\"Running main() from \%s\\n\", __FILE__)",
        "testing::InitGoogleTest(&argc, argv)",
        "return RUN_ALL_TESTS()",
    };
    SrcFile src_file(fileName);
    src_file.SetLibFile(libFiles);
    // src_file.AddUserFile("public_function.h");
    src_file.AddUserFile("gtest/gtest.h");
    src_file.AddSameIncFile();
    src_file.SetHeadValue("Title", "LeetCode算法练习");
    src_file.SetHeadValue("Description", description);
    src_file.AddFunction("int " + publicFuncName + para, funcContent);
    src_file.AddNameSpace("std");
    src_file.CreateFile();
    src_file.CreateIncFile();
}

void LeetCodeFile::CreateMainFile()
{
    string mainName = "main.cpp";
    string funcName = "int main(int argc, char** argv)";
    vector<string> funcContent = {
        "return " + publicFuncName + "(argc, argv)",
    };
    SrcFile src_file(mainName);
    src_file.SetHeadValue("Title", "LeetCode算法练习");
    src_file.SetHeadValue("Description", description);
    src_file.AddFunction(funcName, funcContent);
    src_file.AddUserFile(fileName + ".h");
    src_file.CreateFile();
}

void LeetCodeFile::Init()
{
    int start = netAdress.find("problems") + sizeof("problems");
    int end   = netAdress.find('/', start);
    publicFuncName = "LC" + string(4 - probNum.size(), '0') + probNum + "Test";

    fileName += string(4 - probNum.size(), '0') + probNum;
    fileName += '_';
    for (int i = start; i < end; i++) {
        fileName.push_back(netAdress[i] == '-'? '_': netAdress[i]);
    }

    description = "LeetCode题库" + probNum + "题, " + netAdress;
}