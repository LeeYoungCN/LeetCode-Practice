/*
 * LeetCode算法练习
 * Description  : LeetCode题库55题，https://leetcode-cn.com/problems/jump-game/
 * Author       : 李阳
 * Created      : 2021-05-26
 */
#include <iostream>
#include <vector>
#include "lc0055_jump_game.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        const int dest = N - 1;
        int maxLen = 0;
        for (int i = 0; i < N; i++) {
            if (i <= maxLen) {
                int len = i + nums[i];
                maxLen = max(len, maxLen);
                if (len >= dest) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
};

void LC0055Test(void)
{
    int N = ReadInt();
    vector<int> nums = ReadVector<int>(N);
    Solution solu;
    cout << solu.canJump(nums) << endl;
}