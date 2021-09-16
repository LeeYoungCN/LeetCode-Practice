/*
 * LeetCode算法练习
 * Description  : LeetCode题库4题, https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Author       : 李阳
 * Created      : 2021-09-14
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
#include "lc0093_restore_ip_addresses.h"

using namespace std;

#define MIN_POS 0
#define MAX_POS 3
#define MAX_LEN 3
#define MIN_LEN 1

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> que;
        vector<vector<int>> legalList;
        vector<int> state(MAX_POS + 1);
        dfs(s.size(), MIN_POS, state, legalList);
        return {""};
    }
private:
    void dfs(int total, int pos, vector<int>& state, vector<vector<int>>& legalList)
    {
        if (total < (MAX_POS - pos + 1) || total > (MAX_POS - pos + 1)*3) {
            return;
        }

        if (pos == MAX_POS) {
            state[pos] = total;
            legalList.emplace_back(state);
            WriteVector<int>(state);
            return;
        }

        for (int i = MIN_LEN; i <= MAX_LEN; i++) {
            state[pos] = i;
            dfs(total - i, pos + 1, state, legalList);
        }
    }
};

void LC0093Test()
{
    Solution solu;
    string s = "2552551113";
    solu.restoreIpAddresses(s);
}