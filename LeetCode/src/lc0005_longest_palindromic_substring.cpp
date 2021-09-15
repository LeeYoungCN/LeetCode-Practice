/*
 * LeetCode算法练习
 * Description  : LeetCode题库5题, https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Author       : 李阳
 * Created      : 2021-09-14
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
#include "lc0005_longest_palindromic_substring.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N));
        int maxStart = 0;
        int maxEnd = 0;
        string ret = "";
        for (int tmpLen = 1; tmpLen <= N; tmpLen++) {
            for (int start = 0; start + tmpLen -1 < N; start++) {
                int end = start + tmpLen -1;
                dp[start][end] = (s[start] == s[end]);
                if (tmpLen > 2) {
                    dp[start][end] = dp[start][end] && dp[start+1][end-1];
                }
                if (dp[start][end]) {
                    maxStart = start;
                    maxEnd = end;
                }
            }
        }

        for (int i = maxStart; i <= maxEnd; i++) {
            ret += s[i];
        }

        return ret;
    }
};

void LC0005Test()
{
    string s = "vadda";
    Solution solu;
    auto result = solu.longestPalindrome(s);
    cout << result << endl;
}
