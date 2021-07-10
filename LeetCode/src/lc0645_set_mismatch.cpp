/*
 * LeetCode算法练习
 * Description  : LeetCode题库645题, https://leetcode-cn.com/problems/set-mismatch/
 * Author       : 李阳
 * Created      : 2021-07-08
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#include "public_function.h"
#include "lc0645_set_mismatch.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N  = nums.size();
        vector<int> ret(2);
        int sum1 = (N*(N+1))/2;
        int sum2 = 0;
        int before = 0;
        for (int i = 0; i < N; i++) {
            int num = nums[i];
            sum2 += num;
            if (num == before) {
                ret[0] = num;
            }
            before = num;
        }
        ret[1] = ret[0] - sum2 + sum1;
        return ret;
    }
};

void LC0645Test()
{
    vector<int> nums = {1, 2, 2, 4, 5};
    Solution solu;
    vector<int> ret = solu.findErrorNums(nums);

    WriteVector<int>(ret);
}