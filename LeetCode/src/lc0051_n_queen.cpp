/*
 * LeetCode算法练习
 * Description  : LeetCode题库51题，https://leetcode-cn.com/problems/n-queens/
 * Author       : 李阳
 * Created      : 2021-06-09
 */
#include <iostream>
#include <vector>

#include "lc0051_n_queen.h"
#include "public_function.h"

using namespace std;

class NQueen {
public:
    explicit NQueen(int n):N(n) {
        visit = vector<vector<bool>>(N, vector<bool>(N));
        for (int i = 0; i < N; i++) {
            line += ".";
        }
    }

    ~NQueen() {}

    vector<vector<string>> Run()
    {
        vector<vector<string>> ret;
        for (int j = 0; j < N; j++) {
            board = vector<string>(N, line);
            if (DFS(0, j)){
                ret.push_back(board);
            }
        }
        return ret;
    }

private:
    bool DFS(int x,int y)
    {
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return true;
        }

        if (FindQ(x, y, -1, 0) && FindQ(x, y, -1, 1) && FindQ(x, y, -1, -1)) {
            board[x][y] = 'Q';
            for (int i = 0; i < N; i++) {
                if (DFS(x+1, i)) {
                    return true;
                }
            }
            board[x][y] = '.';
        }
        
        return false;
    }

    bool FindQ(int x, int y, int dirX, int dirY)
    {
        x += dirX;
        y += dirY;
        if (x < 0 || x >= N || y < 0 || y >= N) {
            return true;
        }

        if (board[x][y] == 'Q') {
            return false;
        }

        return FindQ(x, y, dirX, dirY);
    }

private:
    const int N;
    vector<string> board;
    vector<vector<bool>> visit;
    string line = "";
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        NQueen nq(n);
        return nq.Run();
    }
};

void LC0051Test()
{
    const int N = ReadInt();

    Solution solu;
    
    vector<vector<string>> result = solu.solveNQueens(N);

    if (result.empty()) {
        cout << "Empty!" << endl;
    } else {
        for (auto board: result) {
            WriteVector<string>(board);
        }
    }
}