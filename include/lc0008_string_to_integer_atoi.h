/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库8题，https://leetcode-cn.com/problems/string-to-integer-atoi/
 * Author       : 李阳 l0050626
 * Created      : 2021-03-31
 */
#ifndef LC0008_STRING_TO_INTEGER_H
#define LC0008_STRING_TO_INTEGER_H
#include <iostream>

using namespace std;

typedef unsigned int uint;

namespace method1{
    class StringToInteger{
    public:
        static int MyAtoi(string s);
    };

    class Automaton{
    public:
        string getState(const string& state, char c);
    private:
        int getRow(const string& state);
        int getCol(char c);

        const string TABLE[4][4] = {
                {"start", "signed", "in_number", "end"},
                {"end",   "end",    "in_number", "end"},
                {"end",   "end",    "in_number", "end"},
                {"end",   "end",    "end",       "end"}
        };
    };
}

namespace method2{
    class StringToInteger{
    public:
        static int MyAtoi(string s);
    };
}

#endif // LC0008_STRING_TO_INTEGER_H
