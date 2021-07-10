/*
 * LeetCode算法练习
 * Description  : LeetCode题库451题, https://leetcode-cn.com/problems/sort-characters-by-frequency/
 * Author       : 李阳
 * Created      : 2021-07-08
 */

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

 #include "lc0451_sort_characters_by_frequency.h"

using namespace std;;

bool compare(string x, string y) {
    return x.size() > y.size();
}

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> charMap;
        vector<string> stringVec;
        string ret;
        for (char c:s) {
            if (charMap.count(c) == 0) {
                charMap[c] = stringVec.size();
                stringVec.push_back("");
            }
            stringVec[charMap[c]] += c;
        }
        sort(stringVec.begin(), stringVec.end(), compare);
        for (string s: stringVec) {
            ret += s;
        }

        return ret;
    }
};

void LC0451Test()
{
    string s = "tree";
    Solution solu;
    cout << solu.frequencySort(s) << endl;
}