/*
 * LeetCode算法练习
 * Description  : LeetCode题库198题, https://leetcode-cn.com/problems/house-robber/
 * Author       : 李阳
 * Created      : 2021-09-09
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
#include "lc0198_house_robber.h"

using namespace std;

namespace m1{
class Solution {
public:
    int rob(vector<int>& nums) {
        const size_t N = nums.size();
        vector<int> visit(N);
        if (N == 1) {
            return nums[0];
        }
        for (size_t i = 0; i < N && i < 3; i++) {
            if (i < 2) {
                visit[i] = nums[i];;
            } else {
                visit[i] = nums[0] + nums[i];
            }
        }

        for (size_t i = 3; i < N; i++) {
            visit[i] = max(visit[i - 2], visit[i - 3]) + nums[i];
        }
        return max(visit[N-1], visit[N-2]);
    }
};
}

namespace m2{
class Solution {
public:
    int rob(vector<int>& nums) {
        const size_t N = nums.size();
        vector<int> visit(N);
        if (N == 1) {
            return nums[0];
        }
        visit[0] = nums[0];
        visit[1] = max(nums[0], nums[1]);

        for (size_t i = 2; i < N; i++) {
            visit[i] = max(visit[i - 1], visit[i - 2] + nums[i]);
        }
        return visit[N - 1];
    }
};
}

void LC0198Test()
{
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};
    m2::Solution solu;
    cout << solu.rob(nums2) << endl;
}