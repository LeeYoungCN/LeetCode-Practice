/*
 * LeetCode算法练习
 * Description  : LeetCode题库1743题, https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
 * Author       : 李阳
 * Created      : 2021-07-025
 */
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <climits>

#include "public_function.h"
#include "lc1743_restore_the_array_from_adjacent_pairs.h"

using namespace std;

namespace {
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int totalNum = adjacentPairs.size() + 1;
        vector<int> ret(totalNum);
        unordered_map<int, vector<int>> adjMap;
        for (vector<int> pairs: adjacentPairs) {
            adjMap[pairs[0]].emplace_back(pairs[1]);
            adjMap[pairs[1]].emplace_back(pairs[0]);
        }

        for (pair<int, vector<int>> p : adjMap) {
            if (p.second.size() == 1) {
                ret[0] = p.first;
                break;
            }
        }

        ret[1] = adjMap[ret[0]][0];
        for (int i = 2; i < totalNum; i++) {
            vector<int> tmp = adjMap[ret[i -1]];
            ret[i] = (tmp[0] == ret[i-2] ? tmp[1] : tmp[0]);
        }

        return ret;
    }
};
}

void LC1743Test()
{
    vector<vector<int>> adjacentpairs = {
        {2, 1}, {3, 4}, {3, 2},
    };

    Solution solu;

    WriteVector<int>(solu.restoreArray(adjacentpairs));
}