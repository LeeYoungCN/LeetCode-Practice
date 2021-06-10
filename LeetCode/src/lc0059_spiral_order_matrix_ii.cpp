/*
 * LeetCode算法练习
 * Description  : LeetCode题库59题，https://leetcode-cn.com/problems/spiral-matrix-ii/
 * Author       : 李阳
 * Created      : 2021-05-10
 */
#include <iostream>
#include <vector>
#include <map>
#include <utility>

#include "public_function.h"
#include "lc0059_spiral_order_matirx_ii.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        const int maxNum = n*n;
        int tmpNum = 1;
        int x = 0;
        int y = 0;

        vector<vector<int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int loopNum = 0;

        vector<int> dirNow = directions[loopNum];

        while (tmpNum <= maxNum) {
            matrix[x][y] = tmpNum++;
            int nextX = x + dirNow[0];
            int nextY = y + dirNow[1];
            if (nextX < 0 || nextX >= n || 
                nextY < 0 || nextY >= n || 
                matrix[nextX][nextY] != 0) {
                
                loopNum = (loopNum + 1) % 4;
                dirNow = directions[loopNum];
            }
            x += dirNow[0];
            y += dirNow[1];
        }

        return matrix;
    }
};

void LC0059Test(void)
{
    int n;
    n = ReadInt();
    Solution solu;
    vector<vector<int>> matrix = solu.generateMatrix(n);
    for (auto it = matrix.begin(); it != matrix.end(); it++) {
        WriteVector<int>(*it);
        cout << endl;
    }
}