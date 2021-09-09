/*
 * LeetCode算法练习
 * Description  : LeetCode题库1894题, https://leetcode-cn.com/problems/find-the-student-that-will-replace-the-chalk/
 * Author       : 李阳
 * Created      : 2021-09-10
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
#include "lc1894_find_the_student_that_will_replace_the_chalk.h"

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        const int N = chalk.size();
        for (const auto& num : chalk) {
            sum += num;
        }
        k = k % sum;
        for (int i = 0; i < N; i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return 0;
    }
};


void LC1894Test()
{
    ;
}