/*
 * LeetCode算法练习
 * Description  : LeetCode题库443题, https://leetcode-cn.com/problems/string-compression/
 * Author       : 李阳
 * Created      : 2021-08-22
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

#include "public_function.h"
#include "lc0443_string_compression.h"

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        const int N = chars.size();
        pair<char, int> now = {chars[0], 1};
        int len = 0;
        vector<char>::iterator it = chars.begin();
        for (int i = 1; i < N; i++) {
            char c = chars[i];
            if(c == now.first) {
                now.second++;
            } else {
                CharsInsert(it, len, now);
                now.first = c;
                now.second = 1;
            }
        }
        CharsInsert(it, len, now);

        return len;
    }
private:
    void CharsInsert(vector<char>::iterator& it, int& len, pair<char, int>& pairInfo)
    {
        string src = Pair2Str(pairInfo);
        const int N = src.size();
        len += N;
        for (int i = N-1; i >= 0; i--) {
            *it = src[i];
            it++;
        }
    }

    string Pair2Str(pair<char, int>& pairInfo)
    {
        string ret = "";
        int num = pairInfo.second;
        if (num > 1) {
            while (num > 0) {
                ret += num % 10 + '0';
                num /= 10;
            }
        }
        ret += pairInfo.first;
        return ret;
    }
};

void LC0443Test()
{
    vector<char> chars = {'a','a','b','b','c','c','c'};
    Solution solu;
    int len = solu.compress(chars);
    vector<char> result(len);
    for (int i = 0; i < len; i++) {
        result[i] = chars[i];
    }
    WriteVector<char>(result);
}