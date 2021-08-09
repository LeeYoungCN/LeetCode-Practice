/*
 * LeetCode算法练习
 * Description  : LeetCode题库200题, https://leetcode-cn.com/problems/number-of-islands/description/
 * Author       : 李阳
 * Created      : 2021-06-05
 * 
 * [200]岛屿数量
 *
 *
 *https://leetcode-cn.com/problems/number-of-islands/description/
 *
 *
 * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
 * 示例 1:
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * 输出: 1
 * 
 * 示例 2:
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * 输出: 3
 * 
 * 
 */
#include <iostream>
#include <vector>

#include "lc0200_number_of_islands.h"
#include "public_function.h"

using namespace std;

class NumberOfIslands {
public:
    NumberOfIslands(vector<vector<char>>& grid):grid(grid),ROW_NUM(grid.size()),COL_NUM(grid[0].size())
    {
    }

    int numIslands()
    {
        int cnt = 0;
        for (int i = 0; i < ROW_NUM; i++) {
            for (int j = 0; j < COL_NUM; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

private:
    void dfs(int i, int j)
    {
        if (i < 0 || i >= ROW_NUM || j < 0 || j >= COL_NUM) {
            return;
        }

        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(i+1, j);
        dfs(i-1, j);
        dfs(i, j+1);
        dfs(i, j-1);
        
        return;
    }

private:
    vector<vector<char>> grid;
    const int ROW_NUM;
    const int COL_NUM;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        NumberOfIslands ns(grid);
        return ns.numIslands();
    }
};

void LC0200Test()
{
    const int R = ReadInt();
    const int C = ReadInt();

    vector<vector<char>> grid(R, vector<char>());

    Solution solu;

    for (int i = 0; i < R; i++) {
        grid[i] = ReadVector<char>(C);
    }

    cout << solu.numIslands(grid) << endl;
}