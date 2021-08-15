/*
 * LeetCode算法练习
 * Description  : LeetCode题库446题，https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/
 * Author       : 李阳
 * Created      : 2021-08-15
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

using namespace std;

#include "public_function.h"
#include "lc0446_arithmetic_slices_ii_subsequence.h"

typedef long long int DELTA;
typedef           int COUNT;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ret = 0;
        const int N = nums.size();
        vector<unordered_map<DELTA, COUNT>> fn(N);
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                DELTA delta = static_cast<DELTA>(nums[j]) - nums[i];
                auto it = fn[i].find(delta);
                COUNT cnt = (it == fn[i].end() ? 0 : it->second);
                ret += cnt;
                fn[j][delta] += cnt + 1;
            }
        }
        return ret;
    }
};

void LC0446Test()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    Solution solu;
    int ans = solu.numberOfArithmeticSlices(nums);
    cout << ans << endl;
}