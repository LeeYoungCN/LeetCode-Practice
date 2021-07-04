/*
 * LeetCode算法练习
 * Description  : LeetCode题库168题，https://leetcode-cn.com/problems/excel-sheet-column-title/
 * Author       : 李阳
 * Created      : 2021-06-29
 */
#include <iostream>
#include <algorithm>

#include "lc0168_excel_sheet_column_title.h"

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {;
        string ret = "";
        while(columnNumber >0) {
            ret += (columnNumber-1)%26 + 'A';
            columnNumber = (columnNumber-1)/26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

void LC0168Test()
{
    int columnNumber = 100;
    Solution solu;

    cout << solu.convertToTitle(columnNumber) << endl;
}
