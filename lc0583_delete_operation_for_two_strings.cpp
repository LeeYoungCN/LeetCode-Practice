/*
 * LeetCode算法练习
 * Description  : LeetCode题库583题, https://leetcode-cn.com/problems/delete-operation-for-two-strings/
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
#include "lc0583_delete_operation_for_two_strings.h"

using namespace std;

namespace m1{
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int N1 = word1.size();
        const int N2 = word2.size();
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1));
        for (int i = 0; i <= N1; i++) {
            for (int j = 0; j <= N2; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                    continue;
                }
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i - 1][j -1 ] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return N1 + N2 - dp[N1][N2] * 2;
    }
};
}

namespace m2{
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int N1 = word1.size();
        const int N2 = word2.size();
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1));
        for (int i = 0; i <= N1; i++) {
            for (int j = 0; j <= N2; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                    continue;
                }

                if(j == 0) {
                    dp[i][j] = i;
                    continue;
                }

                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i -1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[N1][N2];
    }
};
}

void LC0583Test()
{
    using namespace m2;
    string word1 = "123";
    string word2 = "345";
    Solution solu;
    cout << solu.minDistance(word1, word2) << endl;
}