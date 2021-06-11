/*
 * LeetCode算法练习
 * Description  : LeetCode题库45题，https://leetcode-cn.com/problems/jump-game-ii/description/
 * Author       : 李阳
 * Created      : 2021-05-28
 *
 * [45]跳跃游戏 II
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 示例:
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 *      从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 说明:
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */
#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <set>

#include "lc0045_jump_game_ii.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        const int   size   = nums.size();
        const int   destPos  = size - 1;
        vector<int> layer(size, 0);
        int         maxLen = 0;
        for (int i = 0; i < size; i++) {
            int len = nums[i] + i;
            for (int j = maxLen+1; j <= min(len, destPos); j++) {
                layer[j] = layer[i] + 1;
            }
            maxLen = max(len, maxLen);
            if (len >= destPos) {
                return layer[destPos];
            }

        }
        return layer[destPos];
    }
};


void LC0045Test(void)
{
    int N = ReadInt();
    vector<int> nums = ReadVector<int>(N);
    Solution solu;
    cout << solu.jump(nums) << endl;
}