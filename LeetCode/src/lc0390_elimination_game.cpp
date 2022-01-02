/*
 * LeetCode算法练习
 * Description   : LeetCode题库390题, https://leetcode-cn.com/problems/elimination-game/
 * Author        : 李阳
 * Created       : 2022-01-02 17:04:59
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
#include "lc0390_elimination_game.h"

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int min = 1;
        int max = n;
        int cnt = n;
        int start = min;
        int delta = 1;
        bool flag = true;
        while (cnt > 1) {
            if (cnt % 2 == 1) { // 数量为奇数, 两端变化
                min += (delta);
                max -= (delta);
            } else { // 数量为偶数, start端变化
                if (flag) { // tart == min
                    min += (delta);;
                } else {
                    max -= (delta);
                }
            }
            if (flag) {
                start = max;
            } else {
                start = min;
            }
            flag = !flag;
            cnt /= 2;
            delta *= 2;
        }
        return start;
    }
};

class LC0390TestCase : public testing::Test {
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

    void TestFunc(int rightOutput, int input) {
        EXPECT_EQ(rightOutput, solu.lastRemaining(input));
    }

    Solution solu;
};

TEST_F(LC0390TestCase, test)
{
    TestFunc(6, 9);
}

int LC0390Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

