/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库10题，https://leetcode-cn.com/problems/regular-expression-matching/
 * Author       : 李阳 l0050626
 * Created      : 2021-04-01
 */
#ifndef LC0010_RUGULAR_EXPRESSION_MATCHING_H
#define LC0010_RUGULAR_EXPRESSION_MATCHING_H

#include <iostream>
#include <vector>

using namespace std;

class RegularExpressionMatch{
public:
    static bool isMatch(string s, string p);
};

class Node{
public:
    explicit Node(char key);
    bool push(char x);
    void setNum(int number);

private:
    char key = '.';
    int  num = 0;
    int  weight = 3;
    int  size = 0;

    vector<int> strIndex;

};

#endif // LC0010_RUGULAR_EXPRESSION_MATCH_H