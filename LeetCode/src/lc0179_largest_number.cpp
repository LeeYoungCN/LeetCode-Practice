/*
 * LeetCode算法练习
 * Description  : LeetCode题库179题, https://leetcode-cn.com/problems/largest-number/
 * Author       : 李阳
 * Created      : 2021-09-21
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
#include <numeric>

#include "public_function.h"
#include "lc0179_largest_number.h"

using namespace std;

bool CompareStr(const string& x, const string& y)
{
    string x1 = x + y;
    string y1 = y + x;
    return x1 > y1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strVec;
        for (auto &num : nums) {
            strVec.emplace_back(to_string(num));
        }
        sort(strVec.begin(), strVec.end(), CompareStr);
        if (strVec[0][0] == '0') {
            return "0";
        }
        return accumulate(strVec.begin(), strVec.end(), string(""));
    }
};

void LC0179Test()
{
    vector<int> nums = {0,0, 0, 0, 0, 0, 0 ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Solution solu;
    cout << solu.largestNumber(nums) << endl;
}