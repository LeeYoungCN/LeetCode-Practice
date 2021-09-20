/*
 * LeetCode算法练习
 * Description  : LeetCode题库300题, https://leetcode-cn.com/problems/longest-increasing-subsequence/
 * Author       : 李阳
 * Created      : 2021-09-20
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0300_longest_increasing_subsequence.h"

using namespace std;

namespace dp {
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        int ret = 0;
        vector<int> dp(N);
        for (int i = 0; i < N; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};
}

namespace binary_search {
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        int len = 1;
        vector<int> lenList(2);
        lenList[0] = INT_MIN;
        lenList[1] = nums[0];
        for (int i = 1; i < N; i++) {
            if (nums[i] > lenList.back()) {
                len++;
                lenList.emplace_back(nums[i]);
            } else {
                vector<int>::iterator it = lower_bound(lenList.begin(), lenList.end(), nums[i]);
                *it = nums[i];
            }
        }
        return len;
    }
};
}

void LC0300Test()
{
    using namespace binary_search;
    vector<int> nums = {1,2,3,4,5};
    Solution solu;
    cout << solu.lengthOfLIS(nums) << endl;
}
