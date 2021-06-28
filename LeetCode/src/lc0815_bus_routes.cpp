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

typedef struct{
    int line;
    int step;
} Node;

class BusRoutes {
public:
    BusRoutes(vector<vector<int>>& routes, int source, int target)
    {
        lineNum = routes.size();
        lineMap = vector<vector<int>>(lineNum);

        unordered_map<int, vector<int>> tmp;
        for (int i = 0; i < lineNum; i++){
            vector<int> line = routes[i];
            for(int station: line) {
                for (int l: tmp[station]) {
                    lineMap[i].push_back(l);
                    lineMap[l].push_back(i);
                }
                tmp[station].push_back(i);
            }
        }

        for (int line:tmp[source]) {
            sourceLine.insert(line);
        }

        for (int line: tmp[target]) {
            targetLine.insert(line);
        }
    }

    int Run()
    {
        deque<Node> bfsQue;
        vector<bool> visit(lineNum);

        for (int line: sourceLine) {
            Node node = {line, 1};
            visit[line] = true;
            bfsQue.push_back(node);
        }

        while (!bfsQue.empty()) {
            Node nodeNow = bfsQue.front();
            bfsQue.pop_front();

            if (targetLine.count(nodeNow.line)) {
                return nodeNow.step;
            }
            int stepNext = nodeNow.step + 1;
            for (int lineNext: lineMap[nodeNow.line]) {
                
                if (visit[lineNext]) {
                    continue;
                }
                Node nodeNext = {lineNext, stepNext};
                visit[lineNext] = true;
                bfsQue.push_back(nodeNext);
            }
        }

        return -1;

    }
private:
    unordered_set<int> sourceLine;
    unordered_set<int> targetLine;
    int lineNum;
    vector<vector<int>> lineMap;
};

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        BusRoutes br(routes, source, target);
        return br.Run();
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