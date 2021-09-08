/*
 * LeetCode算法练习
 * Description  : LeetCode题库704题, https://leetcode-cn.com/problems/binary-search/
 * Author       : 李阳
 * Created      : 2021-09-06
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
#include "lc0704_binary_search.h"

using namespace std;

namespace iter {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        int start = 0;
        int end = N;
        do {
            int middle = (start + end) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] > target) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }while (start <= end);

        return-1;
    }
};
}

namespace rec {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();
        return find(0, N-1, target, nums);
    }
private:
    int find(int start, int end, int target, vector<int>& nums) {
        if (start > end) {
            return -1;
        }
        int middle = (start + end) / 2;
        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] > target) {
            return find(start, middle-1, target, nums);

        }
        return find(middle+1, end, target, nums);
    }
};
}

void LC0704Test() {
    ;
}