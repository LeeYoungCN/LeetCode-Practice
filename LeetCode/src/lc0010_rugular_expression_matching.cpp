/*
 * LeetCode算法练习
 * Description  : LeetCode题库10题，https://leetcode-cn.com/problems/regular-expression-matching/
 * Author       : 李阳
 * Created      : 2021-04-01
 */
#include <iostream>
#include <vector>

#include "lc0010_rugular_expression_matching.h"
#include "public_function.h"

using namespace std;
namespace LC0010 {
    class Solution {
    public:
        bool isMatch(string s, string p) {
            const int ROW = s.size();
            const int COL = p.size();
            vector<vector<bool>> table(ROW + 1, vector<bool>(COL + 1,false));

            auto isMatch = [&](int x, int y) {
                if (x == 0) {
                    return false;
                }

                if (p[y-1] == '.') {
                    return true;
                }

                return s[x-1] == p[y-1];
            };

            table[0][0] = true; //两边都为空时，判断为true
            for (int r = 0; r <= ROW; r++) {
                for (int c = 1; c <= COL; c++) {
                    if (p[c-1] == '*') {
                        if (isMatch(r, c-1)) {
                            table[r][c] = (table[r][c-2] || table[r-1][c]);
                        } else {
                            table[r][c] = table[r][c-2];;
                        }
                    } else if (isMatch(r, c)) { // 单字符匹配场景
                        table[r][c] = table[r-1][c-1];
                    }
                }
            }
            return table[ROW][COL];
        }
    };
}


void LC0010Test(void)
{
    string s = ReadLine();
    string p = ReadLine();
    LC0010::Solution solu;

    if (solu.isMatch(s, p)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
