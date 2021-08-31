/*
 * LeetCode算法练习
 * Description  : LeetCode题库1109题, https://leetcode-cn.com/problems/corporate-flight-bookings/
 * Author       : 李阳
 * Created      : 2021-08-31
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
#include "lc1109_corporate_light_bookings.h"

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n);
        for(vector<int> booking : bookings) {
            int start = booking[0] - 1;
            int end = booking[1];
            int num = booking[2];
            ret[start] += num;
            if (end < n) {
                ret[end] -= num;
            }
        }
        for (int i = 1; i < n; i++) {
            ret[i] += ret[i-1];
        }
        return ret;
    }
};

void LC1109Test()
{
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5
    Solution solu;
    auto result = solu.corpFlightBookings(bookings, n);
    WriteVector<int>(result);
}