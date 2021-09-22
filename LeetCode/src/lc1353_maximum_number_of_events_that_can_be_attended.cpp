/*
 * LeetCode算法练习
 * Description  : LeetCode题库725题, https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/
 * Author       : 李阳
 * Created      : 2021-09-22
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
#include "lc1353_maximum_number_of_events_that_can_be_attended.h"

using namespace std;

namespace sort_method {
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0;
        int startDay = 0;
        auto Compare = [&](vector<int>& x, vector<int>& y) {
            return (x[0] > y[0]) || (x[0] == y[0] && x[1] > y[1]);
        };
        sort(events.begin(), events.end(), Compare);
        while (!events.empty()) {
            startDay = events.back()[0] + 1;
            cnt++;
            events.pop_back();
            if (events.empty()) {
                break;
            }
            for (auto it = events.rbegin(); it != events.rend(); it++) {
                if ((*it)[0] < startDay) {
                    (*it)[0] = startDay;
                } else {
                    break;
                }
            }
            sort(events.begin(), events.end(), Compare);
            Refresh(events);
        }
        return cnt;
    }
private:
    void Refresh(vector<vector<int>>& events)
    {
        while (!events.empty() && events.back()[0] > events.back()[1]) {
            events.pop_back();
        }
    }
};
}

namespace priority{
class Compare {
public:
    bool operator()(vector<int>& x, vector<int>& y)
    {
        return x[1] > y[1];
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0;
        priority_queue<vector<int>, vector<vector<int>>, Compare> minHeap;
        sort(events.begin(), events.end(), 
            [](vector<int>& x, vector<int>& y) {return x[0] < y[0];});
        int startDay = events[0][0];
        const int N = events.size();
        int index = 0;
        while (index < N || !minHeap.empty()) {
            while(index < N && events[index][0] <= startDay) {
                minHeap.push(events[index]);
                index++;
            }
            if(!minHeap.empty()) {
                cnt++;
                minHeap.pop();
            }
            startDay++;
            while(!minHeap.empty() && minHeap.top()[1] < startDay) {
                minHeap.pop();
            }
        }
        return cnt;
    }
};
}

namespace multiset_method {
#define MAX_DAY 100001
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<vector<int>> input(MAX_DAY + 1, vector<int>());
        vector<vector<int>> output(MAX_DAY + 1, vector<int>());
        int startDay = INT_MAX;
        int endDay = INT_MIN;
        multiset<pair<int, int>> eventSet;
        int cnt = 0;
        const int N = events.size();
        for (int index = 0; index < N; index++) {
            int tmpStartDay = events[index][0];
            int tmpEndDay = events[index][1] + 1;
            input[tmpStartDay].emplace_back(index);
            output[tmpEndDay].emplace_back(index);
            startDay = min(startDay, tmpStartDay);
            endDay = max(endDay, tmpEndDay);
        }

        for (int dayNum = startDay; dayNum <= endDay; dayNum++) {
            for(auto eventIndex : input[dayNum]) {
                int tmpEndDay = events[eventIndex][1] + 1;
                eventSet.insert(make_pair(tmpEndDay, eventIndex));
            }
            for (auto eventIndex : output[dayNum]) {
                auto it = eventSet.find(make_pair(dayNum, eventIndex));
                if (it != eventSet.end()) {
                    eventSet.erase(it);
                }
            }
            if (!eventSet.empty()) {
                cnt++;
                eventSet.erase(eventSet.begin());
            }
        }
        return cnt;
    }
};
}
void LC1353Test()
{
    vector<vector<int>> events = {{1,4}};
    multiset_method::Solution solu;
    cout << solu.maxEvents(events) << endl;
    
}