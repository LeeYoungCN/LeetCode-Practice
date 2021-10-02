/*
 * LeetCode算法练习
 * Description  : LeetCode题库1436题, https://leetcode-cn.com/problems/destination-city/
 * Author       : 李阳
 * Created      : 2021-10-02
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
#include "lc1436_destination_city.h"

using namespace std;

namespace map {
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> container;
        for (auto& path : paths) {
            container.insert({path[0], path[1]});
        }

        for (auto& [_, dest] : container) {
            if (container.count(dest) == 0) {
                return dest;
            }
        }
        return "";
    }
};
}

namespace set_method {
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> set;
        for (auto &path : paths) {
            set.insert(path[0]);
        }
        for (auto &path : paths) {
            if (!set.count(path[1])) {
                return path[1];
            }
        }
        return "";
    }
};
}

void LC1436Test()
{
    vector<vector<string>> paths = {
        {"1", "2"},
        {"3", "4"},
        {"2", "3"}
    };
    set_method::Solution solu;
    cout << solu.destCity(paths) << endl;
}