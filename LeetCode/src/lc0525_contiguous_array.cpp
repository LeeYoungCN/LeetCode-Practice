/*
 * LeetCode算法练习
 * Description  : LeetCode题库525题, https://leetcode-cn.com/problems/contiguous-array/description/
 * Author       : 李阳
 * Created      : 2021-06-03
 * 
 * [525]连续数组
 *
 *
 *https://leetcode-cn.com/problems/contiguous-array/description/
 *
 *
 * 给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组（的长度）。
 *  
 * 示例 1:
 * 输入: [0,1]
 * 输出: 2
 * 说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
 * 示例 2:
 * 输入: [0,1,0]
 * 输出: 2
 * 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 *  
 * 注意: 给定的二进制数组的长度不会超过50000。
 * 
 */
#include <iostream>
#include <vector>
#include <map>

#include "public_function.h"

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int size = nums.size();
        map<int, int> mp = {{0, -1}};
        int state = 0;
        int maxLen = 0;

        for (int i = 0; i < size; i++) {
            
            if (nums[i]) {
                state++;
            } else {
                state--;
            }

            if (mp.count(state)) {
                int preIdex = mp[state];
                maxLen = max(maxLen, i - preIdex);
            } else {
                mp[state] = i;
            }
        }
        return maxLen;
    }
};

void LC0525Test(void)
{
    const int size = ReadInt();
    vector<int> nums = ReadVector<int>(size);

    Solution solu;
    cout << solu.findMaxLength(nums) << endl;
}