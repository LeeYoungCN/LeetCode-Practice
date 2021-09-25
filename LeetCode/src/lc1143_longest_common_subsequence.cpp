/*
 * LeetCode算法练习
 * Description  : LeetCode题库1143题, https://leetcode-cn.com/problems/longest-common-subsequence/
 * Author       : 李阳
 * Created      : 2021-09-25
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
#include "lc1143_longest_common_subsequence.h"

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int N1 = text1.size();
        const int N2 = text2.size();
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1));
        for (int i = 0; i <= N1; i++) {
            for (int j = 0; j <= N2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (text1[i -1] == text2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[N1][N2];
    }
};

void LC1143Test()
{
    string text1 = "1234";
    string text2 = "34567";
    Solution solu;
    cout << solu.longestCommonSubsequence(text1, text2) << endl;
}

