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

class CompareFunc {
public:
    CompareFunc(int timestamp):timestamp(timestamp){}

    bool operator() (pair<int, string> p)
    {
        return p.first >= timestamp;
    }

private:
    int timestamp;
};

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        container[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ret;
        vector<pair<int, string>> tmp = container[key];
        sort(tmp.begin(), tmp.end(), [](pair<int, string> x, pair<int, string> y) {
            return x.first < y.first;
        });
        if (tmp.begin()->first > timestamp) {
            return "";
        }

        map<int, string>::iterator it = find_if(tmp.begin(), tmp.end(), CompareFunc(timestamp));
        if (it == tmp.end()) {
            it = --(tmp.end());
        } else if (it->first > timestamp){
            it--;
        }
        ret = it->second;
        return ret;
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