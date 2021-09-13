/*
 * LeetCode算法练习
 * Description  : LeetCode题库678题, https://leetcode-cn.com/problems/valid-parenthesis-string/submissions/
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
#include "lc0678_valid_parenthesis_string.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        vector<int> leftStack;
        vector<int> starStack;
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            char c = s[i];
            if (c == '(') {
                leftStack.emplace_back(i);
            } else if (c == ')') {
                if (leftStack.empty() && starStack.empty()) {
                    return false;
                } else if (leftStack.empty()) {
                    starStack.pop_back();
                } else{
                    leftStack.pop_back();
                }
            } else {
                starStack.emplace_back(i);
            }
        }

        while (!leftStack.empty() && !starStack.empty()) {
            if (leftStack.back() > starStack.back()) {
                return false;
            }
            leftStack.pop_back();
            starStack.pop_back();
        }

        return leftStack.empty();
    }
};