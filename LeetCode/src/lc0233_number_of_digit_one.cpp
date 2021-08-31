/*
 * LeetCode算法练习
 * Description  : LeetCode题库233题，https://leetcode-cn.com/problems/number-of-digit-one/
 * Author       : 李阳
 * Created      : 2021-08-13
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#include "public_function.h"
#include "lc0233_number_of_digit_one.h"

class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        unsigned int power = 1;
        unsigned int high = n/10;
        unsigned int low = 0;
        unsigned int cur = n%10;
        while(high + cur) {
            cnt += high * power;
            if (cur > 1) {
                cnt += power;
            } else if (cur == 1) {
                cnt += low + 1;
            }
            
            low = cur*power + low;
            cur = high % 10;
            high /= 10;
            power *= 10;
        }
        return cnt;
    }
};

void LC0233Test()
{
    Solution solu;
    cout << solu.countDigitOne(111) << endl;
}