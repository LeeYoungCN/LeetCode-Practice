/*
 * LeetCode算法练习
 * Description  : LeetCode题库457题, https://leetcode-cn.com/problems/circular-array-loop/
 * Author       : 李阳
 * Created      : 2021-08-07
 */

#include <iostream>

#include <climits>
#include <algorithm>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0457_circular_array_loop.h"

using namespace std;

namespace {
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        const int N = nums.size();
        vector<int> visit(N);

        for (int i = 0; i < N; i++) {
            if(IstLoop(i, nums, visit, N)) {
                return true;
            }
        }

        return false;
    }
private:
    bool IstLoop(int startPos, vector<int>& nums, vector<int>& visit, const size_t& N)
    {
        int loopNum = startPos + 1;
        bool dir = (nums[startPos] > 0); // false: 反向， true:正向
        int next = startPos;
        while (true) {
            if ((nums[next] > 0) != dir) {
                return false;
            }

            if (visit[next] == 0) {
                visit[next] = loopNum;
                int tmp = NextIndex(next, nums[next], N);
                if (tmp == next) {
                    return false;
                }
                next = tmp;
            } else if (visit[next] == loopNum) {
                return true;
            } else {
                return false;
            }
        }
    }

    int NextIndex(int index, int step, int N) {
        int next = index + step%N;
        if (next >= N) {
            next -= N;
        } else if (next < 0){
            next += N;
        }
        return next;
    }
};
}

void LC0457Test()
{
    vector<int> nums1 = {-1, 2};
    Solution solu;
    PrintBool(solu.circularArrayLoop(nums1));
}