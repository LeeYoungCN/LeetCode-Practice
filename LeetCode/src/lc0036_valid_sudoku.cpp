/*
 * LeetCode算法练习
 * Description  : LeetCode题库36题, https://leetcode-cn.com/problems/valid-sudoku/
 * Author       : 李阳
 * Created      : 2021-09-17
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0036_valid_sudoku.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {
        const int N = 9;
        vector< vector<int> > rowTab(N, vector<int>(10));
        vector< vector<int> > colTab(N, vector<int>(10));
        vector< vector <vector<int> > > area(3, vector< vector<int> >(3, vector<int>(10)));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int n = c - '0';
                if (rowTab[i][n] > 0 || colTab[j][n] > 0 || 
                    area[i/3][j/3][n] > 0) {
                    return false;
                } else {
                    rowTab[i][n]++;
                    colTab[j][n]++;
                    area[i/3][j/3][n]++;
                }
            }
        }
        return true;
    }
};

void LC0036Test()
{
    ;
}
