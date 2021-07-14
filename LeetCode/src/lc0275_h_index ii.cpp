/*
 * LeetCode算法练习
 * Description  : LeetCode题库275题, https://leetcode-cn.com/problems/h-index-ii/
 * Author       : 李阳
 * Created      : 2021-07-12
 */
#include <iostream>
#include <algorithm>
#include <vector>

#include "public_function.h"
#include "lc0275_h_index_ii.h"

using namespace std;

namespace m1 {
    class Solution {
    public:
        int hIndex(vector<int> &citations) {
            const int N = citations.size();

            return find(0, N-1, citations, N);
        }
    private:
        int find(int start, int end, vector<int> &citations ,const int& N) {
            int half = (start + end) / 2;
            int ret = N - half;
            if (start == end) {
                return citations[half] >= ret ? ret: 0;
            }

            if (citations[half] >= ret) {
                return find(start, half, citations, N);
            } else {
                return find(half +1 , end, citations, N);
            }
        }
    };
}

namespace m2 {
    class Solution {
    public:
        int hIndex(vector<int> &citations) {
            const int N = citations.size();
            int start = 0;
            int end = N - 1;
            int ret = 0;
            while (start < end) {
                int half = (start + end) / 2;
                ret = N - half;
                if (citations[half] >= ret) {
                    end = half;
                } else {
                    start = half + 1;
                }
            }
            ret = N - start;
            return citations[start] >= ret ? ret : 0;
        }
    };
}


void LC0275Test()
{
    vector<int> citations = {0,1,3,5,6};

    m2::Solution solution;

    cout << solution.hIndex(citations) << endl;
}
