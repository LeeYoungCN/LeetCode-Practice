/*
 * LeetCode算法练习
 * Description  : LeetCode题库79题, https://leetcode-cn.com/problems/word-search/
 * Author       : 李阳
 * Created      : 2021-06-04
 */

#include <iostream>
#include <vector>

#include "lc0084_largest_rectangle_in_histogram.h"
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> stack;
        const int N = heights.size();
        int i = 0;
        while (!stack.empty() || i < N) {
            if(stack.empty() ||(i < N && heights[i] > heights[stack.back()])) {
                stack.emplace_back(i++);
            } else {
                int top  = stack.back();
                stack.pop_back(); // 栈顶元素
                int W = i; // 当堆栈为空时，说明此时为最小值，宽度为此时的下标。
                if (!stack.empty()) {
                    W -= stack.back() + 1;
                }
                int tmpArea = heights[top] * W;
                maxArea = max(maxArea, tmpArea);
            }
        }
        return maxArea;
    }
};

void LC0084Test()
{
    vector<int> height1= {2, 1, 2};
    vector<int> height2 = {2, 1, 5, 6, 2, 3};
    Solution solu;
    cout << solu.largestRectangleArea(height2) << endl;
}