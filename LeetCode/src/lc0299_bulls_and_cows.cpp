/*
 * LeetCode算法练习
 * Description   : LeetCode题库299题, https://leetcode-cn.com/problems/bulls-and-cows/
 * Author        : 李阳
 * Created       : 2021-11-13 17:24:47
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
#include "lc0299_bulls_and_cows.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        const int N = 10;
        const int LEN = secret.size();
        vector<int> secretVec(N);
        vector<int> guessVec(N);
        int aNum = 0;
        int bNum = 0;
        for (int i = 0; i < LEN; i++) {
            if (secret[i] == guess[i]) {
                aNum++;
            } else {
                secretVec[secret[i] - '0']++;
                guessVec[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < N; i++) {
            bNum += min(secretVec[i], guessVec[i]);
        }
        string ret = "";
        ret += to_string(aNum) + "A";
        ret += to_string(bNum) + "B";
        return ret;
    }
};

class LC0299TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void TestFunc(vector<vector<string>> &testCase, string &rightResult)
    {
        for (const vector<string>& testStr : testCase) {
            string tempResult = solu.getHint(testStr[sIndex], testStr[gIndex]);
            EXPECT_EQ(rightResult, tempResult);
        }
    }
    Solution solu;
    const int sIndex = 0;
    const int gIndex = 1;
};

TEST_F(LC0299TestCase, _0A0B)
{
    string rightResult = "0A0B";
    vector<vector<string>> testCase = {
        {"123", "456"},
        {"1", "0"}
    };
    TestFunc(testCase, rightResult);
}

TEST_F(LC0299TestCase, _1A1B)
{
    string rightResult = "1A1B";
    vector<vector<string>> testCase = {
        {"123", "152"},
        {"561", "641"}
    };
    TestFunc(testCase, rightResult);
}

int LC0299Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

