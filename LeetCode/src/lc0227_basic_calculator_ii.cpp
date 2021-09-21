/*
 * LeetCode算法练习
 * Description  : LeetCode题库227题, https://leetcode-cn.com/problems/basic-calculator-ii/
 * Author       : 李阳
 * Created      : 2021-09-21
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
#include "lc0227_basic_calculator_ii.h"

using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> stack;
        auto it = s.begin();
        auto end = s.end();
        stack.emplace_back(GetNum(it, end));
        while (it < end) {
            char symbol = *it++;
            int  num = GetNum(it, end);
            switch (symbol) {
                case '-':
                    num = - num;
                    break;
                case '*':
                    num = stack.back() * num;
                    stack.pop_back();
                    break;
                case '/':
                    num = stack.back() / num;
                    stack.pop_back();
                    break;
                default:
                    break;
            }
            stack.emplace_back(num);
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }
private:
    int GetNum(string::iterator& it, string::iterator& end) {
        int ret = 0;
        DelSpace(it, end);
        while (it != end && *it >= '0' && *it <= '9') {
            ret = 10*ret + (*it - '0');
            it++;
        }
        DelSpace(it, end);
        return ret;
    }

    void DelSpace(string::iterator& it, string::iterator& end) {
        while (it != end && *it == ' ') {
            it++;
        }
    }
};

void LC0227Test() {
    string s = "3+5 / 2";
    Solution solu;
    cout << solu.calculate(s) << endl;
}