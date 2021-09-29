/*
 * LeetCode算法练习
 * Description  : LeetCode题库639题, https://leetcode-cn.com/problems/decode-ways-ii/
 * Author       : 李阳
 * Created      : 2021-09-28
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
#include "lc0639_decode_ways_ii.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        const int N = s.size();
        const int M = 1000000007;
        vector<long long> dp(N+1);
        if (N == 0) {
            return 0;
        }
        dp[0] = 1;
        dp[1] = GetNum(s[0]);
        for (int i = 2; i <= N; i++) {
            dp[i] =  (dp[i - 1] * GetNum(s[i - 1]) + dp[i - 2] * GetNum(s[i - 2], s[i - 1])) % M;
        }
        return dp[N];
    }
private:
    int GetNum(char ch1) {
        int ret = 0;
        switch (ch1) {
            case '*': ret = 9; break;
            case '0': ret = 0; break;
            default:  ret = 1; break;
        }
        return ret;
    }
    int GetNum(char ch1, char ch2)
    {
        int ret = 0;
        if (ch1 != '*' && ch2 != '*') {
            int num = (ch1 - '0') * 10 + (ch2 - '0');
            return num <= 26 && num >= 10 ? 1 : 0;
        };
        if (ch1 == '*' && ch2 == '*') {
            return 15;
        }
        if (ch1 != '*') {
            switch (ch1) {
                case '1': ret = 9; break;
                case '2': ret = 6; break;
                default: break;
            }
        } else {
            ret = ch2 <= '6' ? 2 :1;
        }
        return ret;
    }
};

void LC0639Test()
{
    Solution solu;
    string s = "104";
    cout << solu.numDecodings(s) << endl;
}