/*
 * LeetCode算法练习
 * Description   : LeetCode题库1218题, https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
 * Author        : 李阳
 * Created       : 2021-11-13 18:01:21
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
#include "lc1218_longest_arithmetic_subsequence_of_given_difference.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ret = 0;
        unordered_map<int, int> visit;
        for (const int &value : arr) {
            visit[value] = visit[value - difference] + 1;
            ret = max(ret, visit[value]);
        }
        return ret;
    }
};

class LC1218TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void TestTrue(vector<vector<int>> testCase)
    {
        for (const vector<int>& testVec : testCase) {
            EXPECT_EQ(solu.longestSubsequence(vec));
        }
    }

    Solution solu;
};

TEST_F(LC1218TestCase, 0) {
    ;
}

int LC1218Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

