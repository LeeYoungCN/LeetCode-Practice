/*
 * LeetCode算法练习
 * Description  : LeetCode题库279题, https://leetcode-cn.com/problems/perfect-squares/description/
 * Author       : 李阳
 * Created      : 2021-06-11
 *
 * [279]完全平方数
 *
 *
 *https://leetcode-cn.com/problems/perfect-squares/description/
 *
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 示例 1:
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 示例 2:
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
#include <iostream>
#include <vector>
#include <cmath>

#include "lc0279_perfect_squares.h"
#include "public_function.h"

using namespace std;

namespace{
    class Solution {
    public:
        int numSquares(int n) {
            int sq = sqrt(n);
            vector<int> dp(n+1);

            for (int i = 1; i <= n; i++) {
                dp[i] = i;
                for (int j = 1; j*j <= i; j++) {
                    dp[i] = min(dp[i], dp[i - j*j]+1);
                }
            }

            return dp[n+1];
        }
    };
}


void LC0279Test()
{
    int n = ReadInt();
    Solution solu;
    cout << solu.numSquares(n) << endl;
}