/*
 * LeetCode算法练习
 * Description  : LeetCode题库815题，https://leetcode-cn.com/problems/bus-routes/description/
 * Created      : 2021-06-28
 *
 * [815]公交路线
 *
 *
 *https://leetcode-cn.com/problems/bus-routes/description/
 *
 *
 * 我们有一系列公交路线。每一条路线 routes[i] 上都有一辆公交车在上面循环行驶。例如，有一条路线 routes[0] = [1, 5, 7]，表示第一辆 (下标为0) 公交车会一直按照 1->5->7->1->5->7->1->... 的车站路线行驶。
 * 假设我们从 S 车站开始（初始时不在公交车上），要去往 T 站。 期间仅可乘坐公交车，求出最少乘坐的公交车数量。返回 -1 表示不可能到达终点车站。
 * 
 * 示例:
 * 输入: 
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * 输出: 2
 * 解释: 
 * 最优策略是先乘坐第一辆公交车到达车站 7, 然后换乘第二辆公交车到车站 6。
 * 
 * 说明: 
 * 
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 500.
 * 0 <= routes[i][j] < 10 ^ 6.
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <unordered_set>
#include <unordered_map>

#include "lc0815_bus_routes.h"

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        const int lineNum = routes.size();
        vector<vector<bool>> graph(lineNum, vector<bool>(lineNum));
        unordered_map<int, vector<int>> stationMap;
        vector<int> dis(lineNum, INT_MAX);
        deque<int> bfsQue;

        for (int i = 0; i < lineNum; i++){
            for(int station: routes[i]) {
                for (int l: stationMap[station]) {
                    graph[i][l] = true;
                    graph[l][i] = true;
                }
                stationMap[station].push_back(i);
            }
        }

        for (int station: stationMap[source]) {
            dis[station] = 1;
            bfsQue.push_back(station);
        }

        while (!bfsQue.empty()) {
            int start = bfsQue.front();
            bfsQue.pop_front();

            for (int end = 0; end < lineNum; end++) {
                if (graph[start][end] && dis[end] == INT_MAX) {
                    dis[end] = dis[start] + 1;
                    bfsQue.push_back(end);
                }
            }
        }

        int ret = INT_MAX;

        for (int t: stationMap[target]) {
            ret = min(ret, dis[t]);
        }

        return (ret == INT_MAX ? -1 : ret);
    }
};

void LC0815Test()
{
    vector<vector<int>> routes = {
        {1, 2, 7},
        {3, 6, 7},
    };
    Solution solu;
    cout << solu.numBusesToDestination(routes, 2, 3) << endl;
}