/*
 * LeetCode算法练习
 * Description  : LeetCode题库42题，https://leetcode-cn.com/problems/trapping-rain-water/
 * Author       : 李阳
 * Created      : 2021-06-30
 */
#include <iostream>
#include <vector>
#include <unordered_map>

#include "lc0042_trapping_rain_water.h"

using namespace std;
namespace method1{
    class Solution {
    public:
        int trap(vector<int>& height) {
            const int N = height.size();
            vector<int> leftMax(N);
            vector<int> rightMax(N);
            int ret = 0;
            if (N <= 2) {
                return 0;
            }
            leftMax[0] = height[0];
            rightMax[N - 1] = height[N - 1];
            for (int i = 1; i < N; i++) {
                leftMax[i] = max(leftMax[i - 1], height[i]);
                int j = N - 1 - i;
                rightMax[j] = max(rightMax[j + 1], height[j]);
            }
            for (int i = 0; i < N; i++) {
                ret += min(leftMax[i], rightMax[i]) - height[i];
            }
            return ret;
        }
    };
}


void LC0042Test()
{
    vector<int> height = {4,2,0,3,2,5};
    method1::Solution solu;
    cout << solu.trap(height) << endl;

}