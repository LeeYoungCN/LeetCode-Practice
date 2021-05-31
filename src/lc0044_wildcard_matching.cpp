/*
 * LeetCode算法练习
 * Description  : LeetCode题库44题，https://leetcode-cn.com/problems/wildcard-matching/description/
 * Author       : 李阳
 * Created      : 2021-05-29
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 说明:
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 *  
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 示例 3:
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 示例 4:
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 *  
 * 示例 5:
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */
#include <iostream>
#include <vector>
#include <functional>
#include <string>

#include "lc0044_wildcard_matching.h"
#include "public_function.h"
using namespace std;

namespace Method_1 {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            const int ROW = s.size();
            const int COL = p.size();
            vector<vector<bool>> table(ROW+1, vector<bool>(COL+1, false));

            table[0][0] = true;

            auto matches = [&](int x, int y) {
                if (x == 0) {
                    return false;
                }

                if (p[y-1] == '?') {
                    return true;
                }

                return s[x-1] == p[y-1];
            };

            for (int r = 0; r <= ROW; r++) {
                for (int c = 1; c <= COL; c++) {
                    if (p[c-1] == '*') { // 匹配字符串
                        if (c == 1) {
                            table[r][c] = true;
                        } else if (r == 0) {
                        table[r][c] = table[r][c-1]; 
                        } else {
                            table[r][c] = (table[r][c-1] || table[r-1][c]); 
                        }
                    } else if (matches(r, c)) { // 匹配单个字符
                        table[r][c] = table[r-1][c-1];
                    }
                }
            }
            return table[ROW][COL];
        }
    };
}

namespace Method_2 {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            const int ROW = s.size();
            const int COL = p.size();
            vector<vector<bool>> table(ROW+1, vector<bool>(COL+1, false));

            table[0][0] = true;

            for (int c = 1; c <= COL; c++) {
                if (p[c-1] == '*') {
                    table[0][c] = true;
                } else {
                    break;
                }
            }

            for (int r = 1; r <= ROW; r++) {
                for (int c = 1; c <= COL; c++) {
                    if (p[c-1] == '*') {                                    // 匹配字符串
                        table[r][c] = (table[r][c-1] || table[r-1][c]);          
                    } else if (p[c-1] == '?' || s[r-1] == p[c-1]) {         // 匹配单个字符
                        table[r][c] = table[r-1][c-1];
                    }
                }
            }
            return table[ROW][COL];
        }
    };
}


void LC0044Test(void)
{
    string s = ReadLine();
    string p = ReadLine();
    Method_1::Solution solu;

    if (solu.isMatch(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}