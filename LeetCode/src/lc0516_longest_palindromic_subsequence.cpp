/*
 * LeetCode算法练习
 * Description  : LeetCode题库516题，https://leetcode-cn.com/problems/longest-palindromic-subsequence/
 * Author       : 李阳
 * Created      : 2021-08-22
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#include "public_function.h"
#include "lc0516_longest_palindromic_subsequence.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        const int N = s.length();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = N - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < N; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][N - 1];
    }
};

void LC0516Test()
{
    string s = "abxa";
    Solution solu;
    cout << solu.longestPalindromeSubseq(s) << endl;
}