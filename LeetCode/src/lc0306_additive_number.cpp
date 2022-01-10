/*
 * LeetCode算法练习
 * Description   : LeetCode题库306题, https://leetcode-cn.com/problems/additive-number/
 * Author        : 李阳
 * Created       : 2022-01-10 22:54:24
 */

#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "lc0306_additive_number.h"

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num)
    {
        const int length = num.size();
        if (length < 3) {
            return false;
        }
        for (int len1 = 1; len1 < length; len1++) {
            for (int len2 = 1; len2 < length; len2++) {
                if (max(len1, len2) <= length - len1 - len2) {
                    if (isTrue(len1, len2, num)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isTrue(int len1, int len2, string &num) {
        int length = num.size();
        int p1 = 0;
        int p2 = len1;
        int p3 = len1 + len2;
        int lenMax = max(len1, len2);
        long long int num1 = GetNum(p1, p2, num);
        while (p3 < length) {
            long long int num2 = GetNum(p2, p3, num);
            if (num1 < 0 || num2 < 0) {
                return false;
            }
            int p41 = min(p3 + lenMax, length);
            int p42 = min(p41 + 1, length);
            long long int num3 = GetNum(p3, p41, num);
            if (num3 < 0) {
                return false;
            }
            p1 = p2;
            p2 = p3;
            if (num1 + num2 == num3) {
                num1 = num2;
                num2 = num3;
                p3 = p41;
                continue;
            }
            num3 = GetNum(p3, p42, num);
            if (num3 < 0) {
                return false;
            }
            if (num1 + num2 == num3) {
                num1 = num2;
                num2 = num3;
                p3 = p42;
                lenMax++;
                continue;
            }
            return false;
        }
        return true;
    }

    long long int GetNum(int start, int end, string &num)
    {
        long long int ret = 0;
        if (num[start] == '0' && end - start > 1) {
            return -1;
        }
        for (int i = start; i < end; i++) {
            ret = ret * 10 + num[i] - '0';
        }
        return ret;
    }
};

Solution solu;

TEST(LC0306Test, 0)
{
    EXPECT_FALSE(solu.isAdditiveNumber("111"));
    EXPECT_TRUE(solu.isAdditiveNumber("123"));
    EXPECT_TRUE(solu.isAdditiveNumber("11011"));
    EXPECT_TRUE(solu.isAdditiveNumber("101"));
}


int LC0306Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

