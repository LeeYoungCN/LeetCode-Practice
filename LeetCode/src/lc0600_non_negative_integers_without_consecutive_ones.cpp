/*
 * LeetCode算法练习
 * Description  : LeetCode题库600题, https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
 * Author       : 李阳
 * Created      : 2021-09-11
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
#include "lc0600_non_negative_integers_without_consecutive_ones.h"

using namespace std;

namespace {
class Solution {
public:
    int findIntegers(int n) {
        vector< vector<int> > dp = BuildTable();
        const int maxIndex = GetMaxIndex(n);
        int pre = 0;
        int ans = 0;
        for (int i = maxIndex; i >= 0; i--) {
            int current = (n >> i) & 1;
            if (pre == 1 && current == 1) {
                break;
            }

            ans += dp[i][current];
            pre = current;
        }
        return ans;
    }
private:
    vector< vector<int> > BuildTable()
    {
        const int N = sizeof(int) * 8;
        vector< vector<int> > dp(N, vector<int>(2));
        dp[0][0] = 1;
        dp[0][1] = 2;
        for (int i = 1; i < N; i++) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][0] + dp[i][0];
        }
        return dp;
    }

    int GetMaxIndex(int n) {
        for (int i = 31; i >= 0; i--) {
            if ((1 << i) & n) {
                return i;
            }
        }
        return 0;
    }
};

}


void LC0600Test()
{
    int n = 3;
    Solution solu;
    cout << solu.findIntegers(n) << endl;
}

