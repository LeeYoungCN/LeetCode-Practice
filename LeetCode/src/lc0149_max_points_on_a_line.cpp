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
        const int maxY = 20000;
        int maxNum = 1;
        if (N <= 2) {
            return N;
        }

        for (int i = 0; i < N - 1; i++) {
            unordered_map<int, int> gradMap;
            for (int j = i + 1; j < N; j++) {
                int deltaX = points[j][0] - points[i][0];
                int deltaY = points[j][1] - points[i][1];
                if (deltaX == 0) {
                    deltaY = 1;
                } else if (deltaY == 0) {
                    deltaX = 1;
                }
                if (deltaY < 0) {
                    deltaX = -deltaX;
                    deltaY = -deltaY;
                }
                int gcdXY = gcd(deltaX, deltaY);
                deltaX = deltaX/gcdXY;
                deltaY = deltaY/gcdXY;

                int gradient = deltaY + deltaX * (maxY + 1);
                gradMap[gradient] ++;
            }
            for (auto p: gradMap) {
                maxNum = max(p.second, maxNum);
            }
        }
        return maxNum + 1;
    }

private:
    int gcd(int a, int b)
    {
        return b? gcd(b, a%b): a;
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
