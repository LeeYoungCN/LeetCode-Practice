/*
 * LeetCode算法练习
 * Description  : LeetCode题库168题, https://leetcode-cn.com/problems/find-peak-element/
 * Author       : 李阳
 * Created      : 2021-09-15
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
#include "lc0162_find_peak_element.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        int ans = 0;
        int start = 0;
        int end = N - 1;

        auto getValue = [=](int x) -> pair<int, int> {
            if (x == -1 || x == N) {
                return {0, -1};
            } else {
                return {1, nums[x]};
            }
        };

        while(start <= end) {
            int middle = (start + end) / 2;
            if (getValue(middle) > getValue(middle - 1) && 
                getValue(middle) > getValue(middle + 1)) {
                ans = middle;
                break;
            }

            if (getValue(middle) <= getValue(middle - 1)) {
                end   = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return ans;
    }
};

void LC0162Test()
{
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution solu;
    cout << solu.findPeakElement(nums) << endl;
}