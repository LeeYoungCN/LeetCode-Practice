/*
 * LeetCode算法练习
 * Description  : LeetCode题库413题，https://leetcode-cn.com/problems/arithmetic-slices/
 * Author       : 李阳
 * Created      : 2021-08-12
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
#include "lc0413_arithmetic_slices.h"

namespace {
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        int sum = 0;
        
        if (N < 3) {
            return sum;
        }
        int delta = nums[1] - nums[0];
        int cnt = 0;
        for (int i = 2; i < N; i++) {
            int tmp = nums[i] - nums[i-1];
            if (delta == tmp) {
                cnt++;
            } else {
                delta = tmp;
                cnt=0;
            }
            sum += cnt;
        }
        return sum;
    }
};
}

void LC0413Test()
{
    vector<int> nums = {0, 1, 2, 3};
    Solution solu;
    cout << solu.numberOfArithmeticSlices(nums) << endl;
}
