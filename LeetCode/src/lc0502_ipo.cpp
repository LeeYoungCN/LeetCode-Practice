/*
 * LeetCode算法练习
 * Description  : LeetCode题库502题, https://leetcode-cn.com/problems/ipo/
 * Author       : 李阳
 * Created      : 2021-09-08
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
#include "lc0502_ipo.h"

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int nowCapital = w;
        const size_t N = capital.size();
        vector<pair<int, int>> menu(N);
        size_t curr = 0;
        for (size_t i = 0; i < N; i++) {
            menu[i].first = capital[i];
            menu[i].second = profits[i];
        }
        sort(menu.begin(), menu.end(),[](pair<int, int>& x, pair<int, int>& y){
            return (x.first < y.first) || (x.first == y.first && x.second < y.second);
        });

        priority_queue<int, vector<int>, less<int>> heap;

        for (int i = 0; i < k; i++) {
            while (curr < N && menu[curr].first <= nowCapital) {
                heap.push(menu[curr].second);
                curr++;
            }

            if (!heap.empty()) {
                nowCapital += heap.top();
                heap.pop();
            } else {
                break;
            }

        }
        return nowCapital;
    }
};

void LC0502Test()
{
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    Solution solu;
    cout << solu.findMaximizedCapital(k,w, profits, capital);
}
