/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库8题，https://leetcode-cn.com/problems/string-to-integer-atoi/
 * Author       : 李阳 l0050626
 * Created      : 2021-03-31
 */

#include "lc0008_string_to_integer_atoi.h"

int method1::StringToInteger::MyAtoi(string s) {
    int    sign = 1;
    uint   limit = INT32_MAX;
    uint   newInt = 0;
    string state = "start";
    Automaton automaton;

    for (char c : s) {
        state = automaton.getState(state, c);

        if (state == "start")
            continue;
        if (state == "sign") {
            if (c == '-') {
                sign  = -1;
                limit = limit+1;
            }
            continue;
        }
        if (state == "end")
            break;

        int endNum = c - '0';

        if (limit / 10 < newInt || limit - newInt * 10 <= static_cast<uint>(endNum)) {
            return (int)limit;
        }

        newInt = 10 * newInt + endNum;
    }
    return (int)newInt * sign;
}

string method1::Automaton::getState(const string& state, char c) {
    int row = this->getRow(state);
    int col = this->getCol(c);

    return TABLE[row][col];
}

int method1::Automaton::getRow(const string& state) {
    if (state ==     "start")   return 0;
    if (state ==      "sign")   return 1;
    if (state == "in_number")   return 2;
    if (state ==       "end")   return 3;

    return -1;
}

int method1::Automaton::getCol(char c) {
    if (isspace(c))
        return 0;
    if (c == '+' || c == '-')
        return 1;
    if (isdigit(c))
        return 2;

    return 3;
}

int method2::StringToInteger::MyAtoi(string s) {
    int newInt = 0;
    int index  = 0;
    int length = s.size();

    int symbol = 1;
    int limit = INT32_MAX;

    while(s[index] == ' '){
        index++;
    }

    switch(s[index]){
        case '-': index++, limit = INT32_MIN, symbol = -1; break;
        case '+': index++; break;
    }

    while (s[index] == '0') {
        index++;
    }

    for(size_t i = 0; index < length; i++){
        if (s[index] < '0' || s[index] > '9')    return newInt;

        int endNum = symbol*(s[index++] - 48);

        if (i >= 9) {
            if (INT32_MIN / 10 > newInt || INT32_MAX / 10 < newInt) {
                return limit;
            }

            int delta = abs(limit - newInt*10);
            if (delta < abs(endNum)) {
                return limit;
            }
        }

        newInt = newInt*10+endNum;
    }

    return newInt;
}
