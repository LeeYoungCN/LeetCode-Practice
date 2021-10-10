/*
 * LeetCode算法练习
 * Description   : LeetCode题库441题, https://leetcode-cn.com/problems/arranging-coins/
 * Author        : 李阳
 * Created       : 2021-10-10 11:26:01
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
#include "lc0441_arranging_coins.h"

using namespace std;

namespace {
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        while (n > i) {
            i++;
            n -= i;
        }
        return i;
    }
};

Solution solu;

TEST(SoluTest, ZERO)
{
    EXPECT_EQ(0, solu.arrangeCoins(0));
}

TEST(SoluTest, ONE)
{
    vector<int> input{1, 2};
    int output = 1;
    for (const int & n : input) {
        EXPECT_EQ(output, solu.arrangeCoins(n));
    }
}

TEST(SoluTest, TWO)
{
    vector<int> input{3, 4, 5};
    int output = 2;
    for (const int & n : input) {
        EXPECT_EQ(output, solu.arrangeCoins(n));
    }
}

TEST(SoluTest, THREE)
{
    vector<int> input{6, 7, 8};
    int output = 3;
    for (const int & n : input) {
        EXPECT_EQ(output, solu.arrangeCoins(n));
    }
}

}

int LC0441Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

