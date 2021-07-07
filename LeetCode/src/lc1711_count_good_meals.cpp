/*
 * LeetCode算法练习
 * Description  : LeetCode题库1711题, https://leetcode-cn.com/problems/count-good-meals/submissions/
 * Author       : 李阳
 * Created      : 2021-07-07
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "lc1711_count_good_meals.h"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1'000'000'007;
        int cnt = 0;
        unordered_map<int, int> delMap;
        sort(deliciousness.begin(), deliciousness.end());
        int maxSum = 2 * deliciousness.back();
        int start = 1;
        for (int del: deliciousness) {
            for (int sum = 1; sum <= maxSum; sum *= 2) {
                int target = sum - del;
                if (target < 0) {
                    continue;
                } else if (target > del){
                    break;
                }
                cnt = (cnt + delMap[target])%MOD;
            }
            delMap[del]++;
        }
        return cnt;
    }
};

void LC1711Test()
{
    vector<int> deliciousness = {1, 3, 5, 7, 9};
    vector<int> deliciousness1 = {1,1,1,3,3,3,7};
    Solution solution;
    cout << solution.countPairs(deliciousness1) << endl;
}