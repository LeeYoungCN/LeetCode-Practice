/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库5题，https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Author       : 李阳 l0050626
 * Created      : 2021-03-39
 */

#ifndef LC0005_LONGEST_PALINDROMIC_SUBSTRING_H
#define LC0005_LONGEST_PALINDROMIC_SUBSTRING_H
#include <iostream>
#include <vector>

#include "Pointer.h"

using namespace std;

namespace method1{
    class ZigZagConversion{
    public:
        static string longestPalindrome(string s);
    };
}

namespace method2{
    class ZigZagConversion{
    public:
        static string longestPalindrome(string s);
    private:
        static int expandAroundCenter(string s, int left, int right);
    };
}

namespace method3{
    class ZigZagConversion{
    public:
        static string longestPalindrome(string s);
    private:
        static string toOddLength(string s);
        static int    getArmLen(string s, int left, int right);
        static string subString(string s, int left, int length);
    };
}

#endif // LC0005_LONGEST_PALINDROMIC_SUBSTRING_H