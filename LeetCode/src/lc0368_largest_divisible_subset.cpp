/*
 * LeetCode算法练习
 * Description  : LeetCode题库368题, https://leetcode-cn.com/problems/largest-divisible-subset/
 * Author       : 李阳
 * Created      : 2021-08-23
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0368_largest_divisible_subset.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int N = nums.size();
        vector<int> ret;
        int maxSize = 0;
        int maxIndex = -1;
        vector<int> dp(N, 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] >= maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        for (int i = maxIndex; i >= 0 && maxSize >= 0; i--) {
            int now = nums[i];
            if (dp[i] == maxSize && nums[maxIndex] % now == 0) {
                ret.emplace_back(now);
                maxIndex = i;
                maxSize--;
            }
        }

        return ret;
    }
};

void LC0368Test()
{
    vector<int> nums = {1,2,3, 4};
    Solution solu;
    auto result = solu.largestDivisibleSubset(nums);
    WriteVector<int>(result);
}