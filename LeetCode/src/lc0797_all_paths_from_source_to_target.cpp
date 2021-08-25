/*
 * LeetCode算法练习
 * Description  : LeetCode题库797题, https://leetcode-cn.com/problems/all-paths-from-source-to-target/
 * Author       : 李阳
 * Created      : 2021-08-25
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0797_all_paths_from_source_to_target.h"

using namespace std;

namespace bfs {
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        const int target = graph.size() - 1;
        list<vector<int>> bfsQue = {{0}};
        while (!bfsQue.empty()) {
            vector<int> path = bfsQue.front();
            int source = path.back();
            bfsQue.pop_front();

            if (source == target) {
                ret.emplace_back(path);
                continue;
            }

            for (int next : graph[source]) {
                bfsQue.emplace_back(path);
                bfsQue.back().emplace_back(next);
            }
        }
        return ret;
    }
};
}

namespace dfs {
class DfsSolve {
public:
    DfsSolve(vector<vector<int>>& graph):graph(graph), target(graph.size() - 1)
    {
        dfsStack.emplace_back(0);
    }
    vector<vector<int>> allPathsSourceTarget()
    {
        BfsRec(0);
        return result;
    }
private:
    void BfsRec(int source)
    {
        if (source == target) {
            result.emplace_back(dfsStack);
            return;
        }

        for (int next : graph[source]) {
            dfsStack.emplace_back(next);
            BfsRec(next);
            dfsStack.pop_back();
        }
    }

    vector<vector<int>>& graph;
    const int target;
    vector<int> dfsStack;
    vector<vector<int>>  result;
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        DfsSolve dfs(graph);
        return dfs.allPathsSourceTarget();
    }
};
}

void LC0797Test()
{
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    bfs::Solution solu;
    auto result = solu.allPathsSourceTarget(graph);
    WriteMatrix<int>(result);
}