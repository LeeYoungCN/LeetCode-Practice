/*
 * LeetCode算法练习
 * Description  : LeetCode题库15题，https://leetcode-cn.com/problems/3sum/submissions/
 * Author       : 李阳
 * Created      : 2021-06-03
 */
#include <iostream>
#include <vector>
#include <algorithm>

#include "lc0015_3_sum.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int num1 = 0; num1 < N-2; num1++) {
            if (num1 > 0 && nums[num1] == nums[num1-1]) {
                continue;
            }
            int num3 = N - 1;
            for (int num2 = num1 + 1; num2 < num3; num2++) {
                if (num2 > num1 +1 && nums[num2] == nums[num2-1]) {
                    continue;
                }
                int target = -(nums[num1] + nums[num2]);
                while (nums[num3] > target && num2 < num3-1) {
                    num3--;
                }

                if (nums[num3] == target) {
                    ret.push_back({nums[num1], nums[num2], nums[num3]});
                }
            }
        }
        return ret;
    }
};

void LC0015Test()
{
    const int N = ReadInt();
    vector<int> nums = ReadVector<int>(N);
}