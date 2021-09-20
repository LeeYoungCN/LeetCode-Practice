/*
 * LeetCode算法练习
 * Description  : LeetCode题库650题, https://leetcode-cn.com/problems/restore-ip-addresses/
 * Author       : 李阳
 * Created      : 2021-09-20
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
#define MAX_POS 4
#define MIN_POS 1
#define MAX_LEN 3
#define MIN_LEN 1

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<string> legalIpList;
        Dfs(MIN_POS, s.size(), legalIpList, ret, s);
        return ret;
    }
private:
    void Dfs(int pos, int total, vector<string>& legalIpList, vector<string>& ret, string& s)
    {
        if (total < (MAX_POS - pos + 1) * MIN_LEN || total > (MAX_POS - pos + 1) * MAX_LEN) {
            return;
        }

        if (pos == MAX_POS) {
            string tmpStr = GetString(total, total, s);
            if (tmpStr.size() == 0) {
                return;
            }
            string IP;
            for (auto legal :legalIpList ) {
                IP += legal + '.';
            }
            IP += tmpStr;
            ret.emplace_back(IP);
            return;
        }

        for (int l = MIN_LEN; l <= MAX_LEN && l <= total; l++) {
            string tmpStr = GetString(total, l, s);
            if (tmpStr.size() == 0) {
                continue;
            }
            legalIpList.emplace_back(tmpStr);
            Dfs(pos + 1, total - l, legalIpList, ret, s);
            legalIpList.pop_back();
        }
    }

    string GetString(int total, int l, string& s)
    {
        int start = s.size() - total;
        string ret;
        if (l > 1 && s[start] == '0') {
            return ret;
        }
        for (int i = 0; i < l; i++) {
            ret += s[start + i];
        }
        if (l == 3 && ret > "255") {
            ret = "";
        }
        return ret;
    }
};

void LC0093Test()
{
    string s = "25525511135";
    Solution solu;
    WriteVector<string>(solu.restoreIpAddresses(s));
}