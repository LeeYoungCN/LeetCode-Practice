/*
 * LeetCode算法练习
 * Description  : LeetCode题库130题, https://leetcode-cn.com/problems/surrounded-regions/description/
 * Author       : 李阳
 * Created      : 2021-06-06
 *
 * [130]被围绕的区域
 *
 *
 *https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 示例:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 运行你的函数后，矩阵变为：
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 解释:
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

#include "lc0130_surrounded_regions.h"
#include "public_function.h"

using namespace std;

class SurroundedRegion {
public:
    explicit SurroundedRegion(vector<vector<char>>& board):board(board),ROW_NUM(board.size()),COL_NUM(board[0].size())
    {
        this->visit = vector<vector<bool>>(ROW_NUM, vector<bool>(COL_NUM));
    }

    ~SurroundedRegion() {}

    void solve()
    {
        for (int i = 0; i < ROW_NUM; i++) {
            for (int j = 0; j < COL_NUM; j++) {
                if (i == 0 || i == ROW_NUM - 1 || j == 0 || j == COL_NUM - 1) {
                    DfsItr(i, j);
                }
            }
        }

        for (int i = 0; i < ROW_NUM; i++) {
            for (int j = 0; j < COL_NUM; j++) {
                if(!visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    void DfsRec(int i, int j)
    {
        if (Right(i, j)) {
            visit[i][j] = true;
            DfsRec(i-1, j);
            DfsRec(i+1, j);
            DfsRec(i, j-1);
            DfsRec(i, j+1);
        }
    }

    void DfsItr(int i, int j)
    {
        stack<int> iStack;
        stack<int> jStack;
        iStack.push(i);
        jStack.push(j);

        while(!iStack.empty())
        {
            i = iStack.top();
            j = jStack.top();
            iStack.pop();
            jStack.pop();
            if (Right(i, j)) {
                visit[i][j] = true;
                iStack.push(i+1); jStack.push(j);
                iStack.push(i-1); jStack.push(j);
                iStack.push(i);   jStack.push(j+1);
                iStack.push(i);   jStack.push(j-1);
            }
        }
    }

    void BfsItr(int i, int j)
    {
        queue<int> iQueue;
        queue<int> jQueue;
        iQueue.push(i);
        jQueue.push(j);

        while (!iQueue.empty()){
            i = iQueue.front();
            j = jQueue.front();
            iQueue.pop();
            jQueue.pop();
            if (Right(i, j)) {
                visit[i][j] = true;
                iQueue.push(i+1); jQueue.push(j);
                iQueue.push(i-1); jQueue.push(j);
                iQueue.push(i);   jQueue.push(j+1);
                iQueue.push(i);   jQueue.push(j-1);
            }
        }
    }

    bool Right(int i, int j)
    {
        if (i < 0 || i >= ROW_NUM || j < 0 || j >= COL_NUM) {
            return false;
        }

        if (visit[i][j]) {
            return false;
        }

        if (board[i][j] == 'X') {
            return false;
        }

        return true;
    }

private:
    vector<vector<char>> &board;
    const int ROW_NUM;
    const int COL_NUM;
    vector<vector<bool>> visit;
};


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        SurroundedRegion sg(board);
        sg.solve();
    }
};

void LC0130Test()
{
    const size_t ROW_NUM = ReadInt();
    const size_t COL_NUM = ReadInt();

    vector<vector<char>> board(ROW_NUM, vector<char>(COL_NUM));

    Solution solu;
    solu.solve(board);

    for (vector<char> line: board) {
        WriteVector<char>(line);
    }
}