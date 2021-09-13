/*
 * LeetCode算法练习
 * Description  : LeetCode题库447题, https://leetcode-cn.com/problems/number-of-boomerangs/
 * Author       : 李阳
 * Created      : 2021-09-13
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
#include "lc0447_number_of_boomerangs.h"

using namespace std;

typedef int Distance;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        const size_t N = points.size();
        vector<map<Distance, int>> visit(N);
        int cnt = 0;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = i+1; j < N; j++) {
                Distance distance = CalDitance(points[i], points[j]);
                visit[i][distance]++;
                visit[j][distance]++;
            }
            for (const auto&[_, num] : visit[i]) {
                cnt += num * (num - 1);
            }
        }
        return cnt;
    }
private:
    Distance CalDitance(const vector<int>& x, const vector<int>& y) {
        Distance deltX = x[0] - y[0];
        Distance deltY = x[1] - y[1];
        Distance distance = deltX * deltX + deltY * deltY;
        return distance;
    }
};
