/*
 * LeetCode算法练习
 * Description  : LeetCode题库54题，https://leetcode-cn.com/problems/spiral-matrix/
 * Author       : 李阳
 * Created      : 2021-05-12
 */
#include <iostream>
#include <vector>
#include "lc0054_spiral_order_matrix_i.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ret(0);
        int tmpNum = 1;
        int maxNum = row*col;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        int loopNum = 0;
        vector<int> dirNow = directions[loopNum];
        int x = 0;
        int y = 0;
        while (tmpNum <= maxNum) {
            int value = matrix[x][y];
            ret.push_back(value);
            matrix[x][y] = 0;
            tmpNum++;
            int nextX = x + dirNow[0];
            int nextY = y + dirNow[1];
            if (nextX < 0 || nextX >= row || 
                nextY < 0 || nextY >= col || 
                matrix[nextX][nextY] == 0) {
                
                loopNum = (loopNum + 1) % 4;
                dirNow = directions[loopNum];
            }
            x += dirNow[0];
            y += dirNow[1];
        }
        return ret;
    }
};

void LC0054Test(void)
{
    int row = ReadInt();
    int col = ReadInt();

    vector<vector<int>> matrix(row, vector<int>(col, 0));
    int tmpNum = 1;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix[i][j] = tmpNum++;
        }
    }

    Solution solu;
    WriteVector<int>(solu.spiralOrder(matrix));
}