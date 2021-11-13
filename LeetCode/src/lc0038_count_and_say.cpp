/*
 * LeetCode算法练习
 * Description   : LeetCode题库38题, https://leetcode-cn.com/problems/count-and-say/
 * Author        : 李阳
 * Created       : 2021-11-13 20:07:59
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
#include "lc0038_count_and_say.h"

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        return Trans(countAndSay(n - 1));
    }
private:
    string Trans(string&& input) {
        char pre = input[0];
        int num = 0;
        string s = "";
        for (const char &c : input) {
            if (pre == c) {
                num++;
                pre = c;
            } else {
                s += to_string(num) + pre;
                pre = c;
                num = 1;
            }
        }
        s += to_string(num) + pre;
        return s;
    }
};

class LC0038TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void setUpBeforeClass()
    {
        cout << "setUpBeforeClass()" << endl;
    }

    Solution solu;
};

TEST_F(LC0038TestCase, All)
{
    TestFunc("1",           1);
    TestFunc("11",          2);
    TestFunc("21",          3);
    TestFunc("1211",        4);
    TestFunc("111221",      5);
    TestFunc("312211",      6);
    TestFunc("13112221",    7);
    TestFunc("1113213211",  8);
}

int LC0038Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

