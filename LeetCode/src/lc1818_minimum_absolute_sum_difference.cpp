/*
 * LeetCode算法练习
 * Description  : LeetCode题库1818题, https://leetcode-cn.com/problems/minimum-absolute-sum-difference/
 * Author       : 李阳
 * Created      : 2021-07-14
 */
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "public_function.h"
#include "lc1818_minimum_absolute_sum_difference.h"

using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;
        const int N = nums1.size();
        vector<int> nums1Copy(nums1);
        int maxDelta = 0;
        const int MOD = 1'000'000'007;
        sort(nums1Copy.begin(), nums1Copy.end());
        for (int i = 0; i < N; i++) {
            int delta = abs(nums1[i] - nums2[i]);
            ret = (ret + delta)%MOD;
            int pos = lower_bound(nums1Copy.begin(), nums1Copy.end(), nums2[i]) - nums1Copy.begin();
            if (pos < N) {
                maxDelta = max(maxDelta, delta - (nums1Copy[pos] - nums2[i]));
            }
            if (pos > 0) {
                maxDelta = max(maxDelta, delta - (nums2[i] - nums1Copy[pos - 1]));
            }
        }

        return (ret - maxDelta+MOD)%MOD;
    }
};

void LC1818Test()
{
    vector<int> nums1 = {53,48,14,71,31,55,6,80,28,19,15,40,7,21,69,15,5,42,86,15,11,54,44,62,9,100,2,26,81,87,87,18,45,29,46,100,20,87,49,86,14,74,74,52,52,60,8,25,21,96,7,90,91,42,32,34,55,20,66,36,64,67,44,51,4,46,25,57,84,23,10,84,99,33,51,28,59,88,50,41,59,69,59,65,78,50,78,50,39,91,44,78,90,83,55,5,74,96,77,46};
    vector<int> nums2 = {39,49,64,34,80,26,44,3,92,46,27,88,73,55,66,10,4,72,19,37,40,49,40,58,82,32,36,91,62,21,68,65,66,55,44,24,78,56,12,79,38,53,36,90,40,73,92,14,73,89,28,53,52,46,84,47,51,31,53,22,24,14,83,75,97,87,66,42,45,98,29,82,41,36,57,95,100,2,71,34,43,50,66,52,6,43,94,71,93,61,28,84,7,79,23,48,39,27,48,79};

    Solution solution;

    cout << solution.minAbsoluteSumDiff(nums1, nums2) << endl;
}
