/*
 * LeetCode算法练习
 * Description  : LeetCode题库33题,https://leetcode-cn.com/problems/search-in-rotated-sorted-array/submissions/
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
#include "lc0033_search_in_rotated_sorted_array.h"

using namespace std;

namespace m1 {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        int startNum = nums[0];
        sort(nums.begin(), nums.end());
        auto it = find(nums.begin(), nums.end(), target);
        int ret = -1;

        if (it == nums.end()) {
            return -1;
        }

        int startIndex = find(nums.begin(), nums.end(), startNum) - nums.begin();
        int newIndex = it - nums.begin();

        ret = newIndex - startIndex + (newIndex >= startIndex ? 0 : N);

        return ret;
    }
};
}

namespace m2 {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int N = nums.size();
        int start = 0;
        int end = N - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[0]) { // 左区间
                if (target >= nums[0] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else { // 右区间
                if (target > nums[mid] && target <= nums[N - 1]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
};

void LC0033Test()
{
    ;
}