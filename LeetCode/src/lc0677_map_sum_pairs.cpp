/*
 * LeetCode算法练习
 * Description   : LeetCode题库677题, https://leetcode-cn.com/problems/map-sum-pairs/
 * Author        : 李阳
 * Created       : 2021-11-14 00:13:57
 */

#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "gtest/gtest.h"
#include "lc0677_map_sum_pairs.h"

using namespace std;

class MapSum {
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        map[key] = val;
    }
    
    int sum(string prefix) {
        const int L = prefix.size();
        int ret = 0;
        for(const auto& [key, value] : map) {
            if (key.size() >= L && key.substr(0, L) == prefix) {
                ret += value;
            }
        }
        return ret;
    }
private:
    unordered_map<string, int> map;
};

int LC0677Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

