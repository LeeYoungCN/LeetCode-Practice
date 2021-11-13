/*
 * LeetCode算法练习
 * Description   : LeetCode题库375题, https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
 * Author        : 李阳
 * Created       : 2021-11-13 14:22:54
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
#include "lc0375_guess_number_higher_or_lower_ii.h"

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n+1, vector<int>(n+1));
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                f[i][j] = j + f[i][j - 1];
                for (int k = i; k < j; k++) {
                    int tmp = k + max(f[i][k - 1], f[k + 1][j]);
                    f[i][j] = min(f[i][j], tmp);
                }
            }
        }
        return f[1][n];
    }
};

class LC0375TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    Solution solu;
};

TEST_F(LC0375TestCase, All)
{
    EXPECT_EQ(0, solu.getMoneyAmount(1));
    EXPECT_EQ(1, solu.getMoneyAmount(2));
    EXPECT_EQ(2, solu.getMoneyAmount(3));
    EXPECT_EQ(4, solu.getMoneyAmount(4));
    EXPECT_EQ(6, solu.getMoneyAmount(5));
    EXPECT_EQ(8, solu.getMoneyAmount(6));
    EXPECT_EQ(16, solu.getMoneyAmount(10));
}

int LC0375Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

