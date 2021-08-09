/*
 * LeetCode算法练习
 * Description  : LeetCode题库79题, https://leetcode-cn.com/problems/word-search/
 * Author       : 李阳
 * Created      : 2021-06-04
 *
 * [79]单词搜索
 *
 *
 *https://leetcode-cn.com/problems/word-search/description/
 *
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 示例:
 * board =
 * [
 *   ['A','B','COL_NUM','E'],
 *   ['S','F','COL_NUM','S'],
 *   ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 */

#include <iostream>
#include <vector>

#include "lc0079_word_search.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        this->ROW_NUM = board.size();
        this->COL_NUM = board[0].size();
        this->LENGTH  = word.size();
        this->visit = vector<vector<bool>>(ROW_NUM, vector<bool>(COL_NUM, true)); // true 可以被访问 false 不可以被访问


        for (int i = 0; i < ROW_NUM; i++) {
            for (int j = 0; j < COL_NUM; j++) {
                if(dfs(i,j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i, int j, int index)
    {
        if (index >= LENGTH) { // 当index == LENGTH，说明word的最后一位已经被匹配，返回true
            return true;
        }

        if (i < 0 || i >= ROW_NUM || j < 0 || j >= COL_NUM) { // 越界判断
            return false;
        }

        if (visit[i][j] == false) { // 不能被访问
            return false;
        }

        if (word[index] != board[i][j]) { // 可以被访问，但不匹配
            return false;
        }

        visit[i][j] = false; // 该位置与相应字符匹配，后续不可访问

        // 向下继续搜索
        if (dfs(i+1, j, index+1) ||
            dfs(i-1, j, index+1) ||
            dfs(i, j+1, index+1) ||
            dfs(i, j-1, index+1)) {
            return true; // 后续也可以匹配，返回true。
        }

        visit[i][j] = true; // 后续存在不匹配的情况，该位置可以重新被访问，并返回false.
        return false;
    }

private:
    vector<vector<char>> board;
    string word;
    int ROW_NUM;
    int COL_NUM;
    int LENGTH;
    vector<vector<bool>> visit;
};


void LC0079Test()
{
    const int R = ReadInt();
    const int C = ReadInt();
    vector<vector<char>> board(R);

    for (int i = 0; i < R; i++) {
        board[i] = ReadVector<char>(C);
    }

    string word = ReadLine();
    Solution solu;
    PrintBool(solu.exist(board, word));
}

