/*
 * LeetCode算法练习
 * Description  : LeetCode题库11题，https://leetcode-cn.com/problems/container-with-most-water/
 * Author       : 李阳
 * Created      : 2021-05-16
 */
#include <iostream>
#include <vector>

#include "lc0011_container_with_most_water.h"
#include "public_function.h"

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int length = static_cast<int>( height.size());
        int area = 0;
        for (int i = 0; i < length; i++) {
            for(int j = i; j < length; j++) {
                int tmp = (j-i)*min(height[i], height[j]);
                area = max(tmp, area);
            }
        }
        return area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int x = 0;
        int y = static_cast<int>(height.size()) - 1;

        while (x < y) {
            int tmp = min(height[x], height[y]) * (y - x);
            area = max(area, tmp);
            if (height[x] < height[y]) {
                x++;
            } else {
                y--;
            }
        }
        return area;
    }
};

void LC0011Test(void)
{
    int num = ReadInt();
    vector<int> height = ReadVector<int>(num);
    Solution solu;
    cout << solu.maxArea(height) << endl;
}