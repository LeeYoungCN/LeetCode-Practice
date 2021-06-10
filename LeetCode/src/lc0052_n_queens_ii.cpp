/*
 * LeetCode算法练习
 * Description  : LeetCode题库52题，https://leetcode-cn.com/problems/n-queens-ii/description/
 * Author       : 李阳
 * Created      : 2021-06-10
 *
 * [52]N皇后 II
 *
 *
 *https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 上图为 8 皇后问题的一种解法。
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 示例:
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 *  [".Q..",  // 解法 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // 解法 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <set>

#include "lc0052_n_queens_ii.h"
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

        int Run()
        {
            DFS();
            return ret;
        }

    private:
        void DFS(int x = 0)
        {
            if (x == N) {
                ret++;
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
        int ret = 0;
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

        int Run()
        {
            Next();
            return ret;
        }

    private:
        void Next(int x = 0)
        {
            if (x == N) {
                ret++;
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
        int ret = 0;

        vector<string> board;
        set<int> column;
        set<int> diagonalP; // 向上对角线
        set<int> diagonalN; // 向下对角线
    };

}

class Solution {
public:
    int totalNQueens(int n) {
        NQueen1 nq(n);
        return nq.Run();
    }
};

void LC0052Test()
{
    const int N = ReadInt();

    Solution solu;
    
    int result = solu.totalNQueens(N);

    cout << result << endl;
}