/*
 * LeetCode算法练习
 * Description  : LeetCode题库517题, https://leetcode-cn.com/problems/super-washing-machines/
 * Author       : 李阳
 * Created      : 2021-09-29
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
#include "lc0517_super_washing_machines.h"

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        const int N = machines.size();
        int ret = 0;
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int avg = tot / N;
        int num = 0;
        int sum = 0;
        if (tot % N) {
            return -1;
        }
        for (int mch : machines) {
            num = mch - avg;
            sum = sum + num;
            ret = max(ret, max(abs(sum), num));
        }
        return ret;
    }
};

void LC0517Test()
{
    vector<int> machines = {1, 0, 5};
    Solution solu;
    cout << solu.findMinMoves(machines) << endl;
}