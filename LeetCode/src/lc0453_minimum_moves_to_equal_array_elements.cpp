/*
 * LeetCode算法练习
 * Description   : LeetCode题库453题, https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
 * Author        : 李阳
 * Created       : 2021-11-13 22:59:47
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
#include "lc0453_minimum_moves_to_equal_array_elements.h"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minNum = nums[0];
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret += nums[i] - minNum;
        }
        return ret;
    }
};

class LC0453TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void TestFunc(int rightRst, vector<int> input)
    {
        int output = solu.minMoves(input);
        EXPECT_EQ(rightRst, output);
    }

    Solution solu;
};

TEST_F(LC0453TestCase, ZERO)
{
    TestFunc(0, {1,1,1,1,1,1});
    TestFunc(0, {1});
    TestFunc(0, {1, 1});
}

TEST_F(LC0453TestCase, OTHER)
{
    TestFunc(3, {1, 2, 3});
}

int LC0453Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

