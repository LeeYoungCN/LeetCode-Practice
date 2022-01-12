/*
 * LeetCode算法练习
 * Description   : LeetCode题库306题, https://leetcode-cn.com/problems/increasing-triplet-subsequence/
 * Author        : 李阳
 * Created       : 2022-01-12 23:44:15
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
#include "lc0306_increasing_triplet_subsequence.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int SIZE = nums.size();
        if (SIZE < 3) {
            return false;
        }
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < SIZE; i++) {
            int num = nums[i];
            if (num > second) {
                return true;
            } else if(num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;
    }
};

#define ITEM_OF(arr) static_cast<int>(sizeof(arr) / sizeof(arr[0]))

class LC0038TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
    void TestFunc(const int* arr, const int len, const int i)
    {
        vector<int> testCase (arr, arr + len);
        EXPECT_TRUE(solu.increasingTriplet(testCase)) << "index = " << i;
    }
    Solution solu;
};

TEST_F(LC0038TestCase, TRUE)
{
    int testCaseSuit[][6] = {
        {1, 2, 3},
        {4, 5, 6, 8, 9, 10},
        {2, 1, 3, 4, 8, 7},
        {4, 5, 6,}
    };
    
    for (int i = 0; i < ITEM_OF(testCaseSuit); i++) {
        TestFunc(testCaseSuit[i], ITEM_OF(testCaseSuit[i]), i);
    }
}

int LC0306Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

