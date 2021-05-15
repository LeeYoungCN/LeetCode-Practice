/*
 * LeetCode算法练习
 * Description  : LeetCode题库5题，https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Author       : 李阳
 * Created      : 2021-03-29
 */

#ifndef LC0005_LONGEST_PALINDROMIC_SUBSTRING_H
#define LC0005_LONGEST_PALINDROMIC_SUBSTRING_H
#include <iostream>
#include <vector>

#include "matrix.h"

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