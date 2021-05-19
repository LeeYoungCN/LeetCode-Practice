/*
 * LeetCode算法练习
 * Description  : LeetCode题库994题，https://leetcode-cn.com/problems/rotting-oranges/
 * Author       : 李阳
 * Created      : 2021-05-19
 */
#include <iostream>
#include <vector>

#include "lc0994_rotting_oranges.h"
#include "public_function.h"

using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        int row = static_cast<int>(grid.size());
        int col = static_cast<int>(grid[0].size());
        int cnt = 0;

        vector<pair<int, int>> rotting;

        vector<pair<int, int>> dir = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1}
        };

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int value = grid[i][j];
                if (value == 2) {
                    rotting.push_back({i, j});
                } else if (value == 1) {
                    cnt++;
                }
            }
        }

        while (!rotting.empty() && cnt > 0) {
            vector<pair<int, int>> tmp;
            for (pair<int, int> p: rotting) {
                for (pair<int, int> d: dir) {
                    int nextX = p.first + d.first;
                    int nextY = p.second + d.second;
                    if ( nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && grid[nextX][nextY] == 1) {
                        tmp.push_back({nextX, nextY});
                        grid[nextX][nextY] = 2;
                        cnt--;
                    }
                }
            }
            rotting = tmp;
            minute++;
        }
        if (cnt == 0) {
            return minute;
        } else {
            return -1;
        }
    }
};

void LC0904(void)
{
    int row = ReadInt();
    int col = ReadInt();
    vector<vector<int>> grid;
    Solution solu;
    for (int i = 0; i < row; i++) {
        grid.push_back(ReadVector<int>(col));
    }

    cout << solu.orangesRotting(grid) << endl;
}