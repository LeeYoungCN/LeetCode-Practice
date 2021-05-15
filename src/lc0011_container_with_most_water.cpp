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

class Solution {
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

void LC0011Test(void)
{
    int num = ReadInt();
    vector<int> height = ReadVector<int>(num);
    Solution solu;
    cout << solu.maxArea(height) << endl;
}