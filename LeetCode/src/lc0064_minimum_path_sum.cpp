/*
 * LeetCode算法练习
 * Description  : LeetCode题库64题，https://leetcode-cn.com/problems/minimum-path-sum/description/
 * Author       : 李阳
 * Created      : 2021-06-18
 *
 *64]最小路径和
 *©
 *
 *https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 * 示例:
 * 输入:
 * [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <climits>

#include "lc0064_minimum_path_sum.h"
#include "public_function.h"

using namespace std;

class MinPahtSum {
public:
    explicit MinPahtSum(vector<vector<int>>& grid):
    grid(grid), ROW_NUM(grid.size()), COL_NUM(grid[0].size()) {
        dp = vector<vector<int>>(ROW_NUM+1, vector<int>(COL_NUM+1, INT_MAX));
    }

    ~MinPahtSum() {}

    int Go()
    {
        for (int i = ROW_NUM -1; i >= 0; i--) {
            for (int j = COL_NUM-1; j >= 0; j--) {
                if (i == ROW_NUM - 1 && j == COL_NUM-1) {
                    dp[i][j] = grid[i][j];
                } else{
                    dp[i][j] = min (dp[i+1][j], dp[i][j+1])+grid[i][j];
                }   
            }
        }
        return dp[0][0];
    }
private:
    const int ROW_NUM;
    const int COL_NUM;
    vector<vector<int>>& grid;
    vector<vector<int>> dp;
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        MinPahtSum m(grid);
        return m.Go();
    }
};


void LC0064Test()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},  
    };

    Solution solu;

    cout << solu.minPathSum(grid) << endl;
}