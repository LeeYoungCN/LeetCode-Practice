/*
 * LeetCode算法练习
 * Description   : LeetCode题库598题, https://leetcode-cn.com/problems/range-addition-ii/
 * Author        : 李阳
 * Created       : 2021-11-13 23:59:30
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
#include "lc0598_range_addition_ii.h"

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minRow = m;
        int minCol = n;
        for(const auto& op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }
        return minRow*minCol;
    }
};

int LC0598Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

