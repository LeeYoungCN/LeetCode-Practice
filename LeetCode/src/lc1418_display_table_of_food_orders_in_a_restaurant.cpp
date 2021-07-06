/*
 * LeetCode算法练习
 * Description  : LeetCode题库1418题，https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/submissions/
 * Author       : 李阳
 * Created      : 2021-07-06
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

#include "lc1418_display_table_of_food_orders_in_a_restaurant.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ret = {{"Table"}};
        map<int, map<string, int>> tmpMap;
        const int N = orders.size();
        set<string> foodSet;
        for (int i = 0; i < N; i++) {
            int table = str2int(orders[i][1]);
            string food  = orders[i][2];

            tmpMap[table][food]++;
            foodSet.insert(food);
        }
        int foodNum = foodSet.size();

        for (const string& food : foodSet) {
            ret[0].push_back(food);
        }

        for (const pair<const int, map<basic_string<char>, int>>& tableInfo : tmpMap) {
            vector<string> table(foodNum+1, "0");
            table[0] = to_string(tableInfo.first);
            auto foodMap = tableInfo.second;
            for (int i = 1; i < foodNum+1; i++) {
                string food = ret[0][i];
                if (foodMap.find(food) == foodMap.end()) {
                    continue;
                }
                table[i] = to_string(foodMap[food]);
            }
            ret.push_back(table);
        }
        return ret;
    }

    int str2int(string s) {
        int ret = 0;
        for (int c: s) {
            ret = ret*10 + c - '0';
        }
        return ret;
    }
};

void LC1418Test()
{
    ;
}
