/*
 * LeetCode算法练习
 * Description  : LeetCode题库51题，https://leetcode-cn.com/problems/n-queens/
 * Author       : 李阳
 * Created      : 2021-06-09
 *
 * [51]N皇后
 *
 *
 *https://leetcode-cn.com/problems/n-queens/description/
 *
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 上图为 8 皇后问题的一种解法。
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 示例:
 * 输入: 4
 * 输出: [
 *  [".Q..",  // 解法 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // 解法 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <set>

#include "lc0051_n_queens.h"
#include "public_function.h"

using namespace std;
namespace {
    class NQueen1 {
    public:
        explicit NQueen1(int n):N(n) {
            string line = "";
            for (int i = 0; i < N; i++) {
                line += ".";
            }
            board = vector<string>(N, line);
        }

        ~NQueen1() {}

        vector<vector<string>> Run()
        {
            DFS();
            return ret;
        }

    private:
        void DFS(int x = 0)
        {
            if (x == N) {
                ret.push_back(board);
                return;
            }

            for (int y = 0; y < N; y++) {
                if (!(IsValid(x, y, -1, 0) && IsValid(x, y, -1, 1) && IsValid(x, y, -1, -1))) {
                    continue;
                }
                board[x][y] = 'Q';
                DFS(x+1);      
                board[x][y] = '.';
            }
        }

        bool IsValid(int x, int y, int dirX, int dirY)
        {
            x += dirX;
            y += dirY;
            if (x < 0 || x >= N || y < 0 || y >= N) {
                return true;
            }

            if (board[x][y] == 'Q') {
                return false;
            }

            return IsValid(x, y, dirX, dirY);
        }

    private:
        const int N;
        vector<string> board;
        vector<vector<string>> ret;
    };

    class NQueen2 {
    public:
        explicit NQueen2(int n):N(n)
        {
            string line = "";
            for (int i = 0; i < N; i++) {
                line += '.';
            }
            board = vector<string>(N, line);
        }

        ~NQueen2() {};

        vector<vector<string>> Run()
        {
            Next();
            return ret;
        }

    private:
        void Next(int x = 0)
        {
            if (x == N) {
                ret.push_back(board);
                return;
            }

            for (int y = 0; y < N; y++) {
                int d1 = y + x;
                int d2 = y - x;

                if (column.count(y) + diagonalP.count(d1) + diagonalN.count(d2)) {
                    continue;
                }

                board[x][y] = 'Q';
                column.insert(y);
                diagonalP.insert(d1);
                diagonalN.insert(d2);

                Next(x+1);

                board[x][y] = '.';
                column.erase(y);
                diagonalP.erase(d1);
                diagonalN.erase(d2);
            }
        }

    private:
        const int N;
        vector<vector<string>> ret;

        vector<string> board;
        set<int> column;
        set<int> diagonalP; // 向上对角线
        set<int> diagonalN; // 向下对角线
    };
}


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        NQueen1 nq(n);
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
