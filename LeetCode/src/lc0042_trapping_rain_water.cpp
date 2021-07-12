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

class Solution1 {
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

class Solution2 {
public:
    int trap(vector<int>& height)
    {
        int cnt = 0;
        vector<int> stack;
        const int N = height.size();
        if (N <= 2) {
            return 0;
        }
        int top = -1;
        int i = 0;
        while (i < N) {
            if (stack.empty() || height[i] <= height[top]) {
                top = i;
                stack.push_back(i++);
                continue;
            }
            int tmp = top;
            stack.pop_back();
            if (!stack.empty()) {
                top = stack.back();
                int h = min(height[i], height[top]) - height[tmp];
                int w = i - top - 1;
                cnt += h * w;
            }
        }
        return cnt;
    }
};

class Solution3 {
public:
    int trap(vector<int>& height)
    {
        int cnt = 0;
        const int N = height.size();
        int left = 0;
        int right = N - 1;

        int leftMax = 0;
        int rightMax = 0;

        while (left < right) {
            leftMax  = max(height[left],  leftMax);
            rightMax = max(height[right], rightMax);
            if (leftMax < rightMax) {
                cnt += leftMax - height[left];
                left++;
            } else {
                cnt += rightMax - height[right];
                right--;
            }
        }

        return cnt;
    }
};

void LC0042Test()
{
    vector<int> height = {4,2,0,3,2,5};
    Solution2 solu;
    cout << solu.trap(height) << endl;

}