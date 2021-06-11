/*
 * LeetCode算法练习
 * Description  : LeetCode题库523题, https://leetcode-cn.com/problems/continuous-subarray-sum/description/
 * Author       : 李阳
 * Created      : 2021-05-19
 *
 * [523]连续的子数组和
 *
 *
 * https://leetcode-cn.com/problems/continuous-subarray-sum/description/
 *
 *
 * 给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。
 * 示例 1:
 * 输入: [23,2,4,6,7], k = 6
 * 输出: True
 * 解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
 * 
 * 示例 2:
 * 输入: [23,2,6,4,7], k = 6
 * 输出: True
 * 解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
 * 
 * 说明:
 * 
 * 数组的长度不会超过10,000。
 * 你可以认为所有数字总和在 32 位有符号整数范围内。
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "lc0523_continuous_subarray_sum.h"
#include "public_function.h"

using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<vector<int>> sum(N, vector<int>(N));
        sum[0][0] = nums[0];
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                if (i == 0) {
                    sum[i][j] = sum[i][j-1] + nums[j];
                } else {
                    sum[i][j] = sum[i-1][j] - nums[i-1];
                }

                if (sum[i][j] % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
};

void LC0523Test(void)
{
    const int N = ReadInt();
    vector<int> nums = ReadVector<int>(N);
    const int k = ReadInt();

    Solution solu;

    if (solu.checkSubarraySum(nums, k)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}