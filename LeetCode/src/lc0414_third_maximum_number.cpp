/*
 * LeetCode算法练习
 * Description   : LeetCode题库414题, https://leetcode-cn.com/problems/third-maximum-number/
 * Author        : 李阳
 * Created       : 2021-10-06 09:22:02
 */

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "lc0414_third_maximum_number.h"
#include "public_function.h"

using namespace std;

struct Compare {
    bool operator() (const int& x, const int& y) const {
        return x > y;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const int N = 3;
        set<int, Compare> maxSet(nums.begin(), nums.end());
        set<int, Compare>::iterator it = maxSet.begin();
        if(maxSet.size() >= N) {
            for (int i = 1; i < N; i++, it++);
        }
        return *(it);
    }
};

void LC0414Test()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution solu;
    cout << solu.thirdMax(nums) << endl;
}
