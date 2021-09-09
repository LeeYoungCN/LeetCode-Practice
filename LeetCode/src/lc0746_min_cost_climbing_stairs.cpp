/*
 * LeetCode算法练习
 * Description  : LeetCode题库746题, https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * Author       : 李阳
 * Created      : 2021-09-09
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

#include "public_function.h"
#include "lc0746_min_cost_climbing_stairs.h"

using namespace std;

namespace {
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N  = cost.size();
        vector<int> visit(N);
        visit[0] = cost[0];
        visit[1] = cost[1];
        for (int i = 2; i < N; i++) {
            visit[i] = min(visit[i - 1]+ cost[i], visit[i - 2] + cost[i]);
        }
        return min(visit[N-1], visit[N-2]);
    }
};
}

namespace m2 {
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N  = cost.size();
        vector<int> visit(N + 1);
        visit[0] = 0;
        visit[1] = 0;
        for (int i = 2; i <= N; i++) {
            visit[i] = min(visit[i - 1] + cost[i - 1], visit[i - 2] + cost[i - 2]);
        }
        return visit[N];
    }
};
}

void LC0746Test()
{
    vector<int> cost = {10, 15, 20};
    m2::Solution solu;
    cout << solu.minCostClimbingStairs(cost) << endl;
}