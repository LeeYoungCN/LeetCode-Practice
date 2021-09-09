/*
 * LeetCode算法练习
 * Description  : LeetCode题库165题, https://leetcode-cn.com/problems/compare-version-numbers/
 * Author       : 李阳
 * Created      : 2021-09-01
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0165_compare_version_numbers.h"

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto it1 = version1.begin();
        auto it2 = version2.begin();
        auto end1 = version1.end();
        auto end2 = version2.end();
        while (it1 != end1 || it2 != end2) {
            string numStr1 = GetNumStr(it1, end1);
            string numStr2 = GetNumStr(it2, end2);
            int num1 = Str2Int(numStr1);
            int num2 = Str2Int(numStr2);
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }

        return 0;
    }
private:
    string GetNumStr(string::iterator& it, string::iterator end) {
        const char splitChar = '.';
        string ret = "0";
        while (it != end && *it != splitChar) {
            ret += *it;
            ++it;
        }
        if (it != end) {
            ++it;
        }

        return ret;
    }

    int Str2Int(string str) {
        auto it = str.begin();
        int ret = 0;
        while (*it == '0') {
            ++it;
        }

        while (it != str.end()) {
            ret = 10 * ret + (*it - '0');
            ++it;
        }

        return ret;
    }
};

void LC0165Test()
{
    string version1 = "1.001";
    string version2 = "1.1";
    Solution solu;
    cout << solu.compareVersion(version1, version2) << endl;
}