/*
 * LeetCode算法练习
 * Description  : LeetCode题库981题, https://leetcode-cn.com/problems/time-based-key-value-store/
 * Author       : 李阳
 * Created      : 2021-07-10
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "lc0981_time_based_key_value_store.h"

using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        container[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& tmp = container[key];
        pair<int, string> bound = {timestamp, string({127})};
        auto it = upper_bound(tmp.begin(), tmp.end(), bound);
        if (it != tmp.begin()) {
            return (it-1)->second;
        }
        return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> container;
};




/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */