/*
 * LeetCode算法练习
 * Description  : LeetCode题库149题, https://leetcode-cn.com/problems/max-points-on-a-line/
 * Author       : 李阳
 * Created      : 2021-06-29
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "lc0149_max_points_on_a_line.h"

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int N = points.size();
        int maxNum = 1;
        if (N == 1) {
            return 1;
        }

        for (int i = 0; i < N - 1; i++) {
            vector<int> point_i = points[i];
            unordered_map<float, int> gradMap;
            for (int j = i + 1; j < N; j++) {
                vector<int> point_j = points[j];
                int deltaX = point_j[0] - point_i[0];
                int deltaY = point_j[1] - point_i[1];
                float gradient = (deltaX ? (float)deltaY/deltaX: INT_MAX);
                gradMap[gradient] ++;
            }

            for (auto p: gradMap) {
                maxNum = max(p.second, maxNum);
                cout << maxNum << endl;
            }
        }
        return maxNum + 1;
    }
};

void LC0149Test()
{
    vector<vector<int>> points = {
            {0, 0}, {4, 5}, {7, 8}, {8, 9},
            {5, 6}, {3, 4}, {1, 1}
    };

    Solution solu;
    cout << solu.maxPoints(points) << endl;
}
