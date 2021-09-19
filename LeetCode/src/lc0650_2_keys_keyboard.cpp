/*
 * LeetCode算法练习
 * Description  : LeetCode题库650题, https://leetcode-cn.com/problems/2-keys-keyboard/
 * Author       : 李阳
 * Created      : 2021-09-19
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
#include "lc0650_2_keys_keyboard.h"

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ret = 0;
        while (n > 1) {
            ret += GetStep(n);
        }
        return ret;
    }
private:
    int GetStep(int& n)
    {
        int step = n % 2 + 2;
        int nextN = 0;
        int tmp = n;
        n = 1;
        do {
            nextN = tmp / step;
            if (tmp % step == 0) {
                n = nextN;
                break;
            }
            step += 2;
        } while(step < nextN);

        return n == 1 ? tmp : step;
    }
};

void LC0650Test()
{
    int n = 4;
    Solution solu;
    cout << solu.minSteps(n) << endl;
}
