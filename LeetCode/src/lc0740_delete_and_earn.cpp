/*
 * LeetCode算法练习
 * Description  : LeetCode题库740题, https://leetcode-cn.com/problems/delete-and-earn/
 * Author       : 李阳
 * Created      : 2021-09-04
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0740_delete_and_earn.h"

using namespace std;
namespace {
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> countMap;
        for (int &num : nums) {
            countMap[num] += num;
        }
        int N = countMap.size();
        vector<pair<int, int>> visit(N);
        map<int, int>::iterator it = countMap.begin();
        visit[0] = *it++;
        for (int i = 1; i < N; i++, it++) {
            visit[i] = *it;
            if (visit[i - 1].first != it->first - 1) {
                visit[i].second += visit[i - 1].second;
                continue;
            }
            visit[i].second += (i - 2 >= 0 ? visit[i - 2].second : 0);
            visit[i].second = max(visit[i].second, visit[i-1].second);
        }

        return visit[N-1].second;
    }
};
}

namespace DP {
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> numCnts;
        pair<int, int> tmp = {nums[0], 0};
        for (int &num : nums) {
            if (tmp.first == num) {
                tmp.second += num;
            } else {
                numCnts.emplace_back(tmp);
                tmp = {num, num};
            }
        }
        numCnts.emplace_back(tmp);
        int N = numCnts.size();

        for (int i = 1; i < N; i++) {
            int next = i - (numCnts[i].first - numCnts[i-1].first > 1 ? 1 : 2);
            numCnts[i].second += (next >= 0 ? numCnts[next].second : 0);
            numCnts[i].second = max(numCnts[i].second, numCnts[i-1].second);
        }
        return numCnts[N-1].second;
    }
};
}

void LC0740Test()
{
    vector<int> nums = {2, 2, 3, 4, 5};
    DP::Solution solu;
    cout << solu.deleteAndEarn(nums) << endl;
}