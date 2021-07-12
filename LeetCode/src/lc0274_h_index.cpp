/*
 * LeetCode算法练习
 * Description  : LeetCode题库274题, https://leetcode-cn.com/problems/h-index/
 * Author       : 李阳
 * Created      : 2021-07-12
 */
#include <iostream>
#include <algorithm>
#include <vector>

#include "public_function.h"
#include "lc0274_h_index.h"

using namespace std;

namespace {
    class Solution {
    public:
        int hIndex(vector<int> &citations) {
            sort(citations.begin(), citations.end());
            const int N = citations.size();

            for (int i = 0; i < N; i++) {
                if (citations[i] >= N -i) {
                    return N - i;
                }
            }
            return 0;
        }
    };
}

void LC0274Test()
{
    vector<int> citations = {3, 0, 6, 1, 5};

    Solution solution;

    cout << solution.hIndex(citations) << endl;
}
