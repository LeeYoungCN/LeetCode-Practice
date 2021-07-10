/*
 * LeetCode算法练习
 * Description  : LeetCode题库930题，https://leetcode-cn.com/problems/binary-subarrays-with-sum/
 * Author       : 李阳
 * Created      : 2021-07-08
 */

#include <iostream>
#include <vector>
#include <unordered_map>

#include "public_function.h"
#include "lc0930_binary_subarrays_with_sum.h"

using namespace std;

namespace m1 {
    class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int cnt = 0;
            int sum = 0;
            unordered_map<int, int> sumMap = {{0,1}};
            for (int num:nums) {
                sum += num;
                if (sum >= goal){
                    cnt += sumMap[sum - goal];
                }
                sumMap[sum]++;
            }
            return cnt;
        }
    };
}

namespace m2 {

    class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            int cnt = 0;
            int sum1 = 0;
            int sum2 = 0;
            int left1 = 0;
            int left2 = 0;
            int right = 0;
            const int N = nums.size();
            while (right < N) {
                sum1 += nums[right];
                sum2 += nums[right];
                while (left1 <= right && sum1 >  goal) {
                    sum1 -= nums[left1++];
                }
                while (left2 <= right && sum2 >= goal) {
                    sum2 -= nums[left2++];
                }
                cnt += left2 - left1;
                right++;
            }
            return cnt;
        }
    };

}

void LC0930Test()
{
    using namespace m2;
    vector<pair<vector<int>, int>> inputs = {
        {{1, 0, 1, 0, 1}, 2},
        {{0, 0, 0, 0, 0}, 0},
        {{1, 1, 1, 1, 1}, 2}
    };
    int N = inputs.size();
    for (int i = 0; i < N; i++) {
        pair<vector<int>, int> input = inputs[i];
        Solution solution;
        cout << solution.numSubarraysWithSum(input.first, input.second) << endl;
    }
}