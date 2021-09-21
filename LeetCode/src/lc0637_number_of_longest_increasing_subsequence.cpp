/*
 * LeetCode算法练习
 * Description  : LeetCode题库637题, https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
 * Author       : 李阳
 * Created      : 2021-09-20
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
#include "lc0637_number_of_longest_increasing_subsequence.h"

using namespace std;

namespace dp {
struct LenNode {
    int len;
    int cnt;
    LenNode() : len(1), cnt(1) {};
    LenNode(int v) : len(v), cnt(1) {};
    LenNode(int v, int n) : len(v), cnt(n) {};

};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();
        vector<LenNode> lenList(N);
        LenNode maxNode(0,0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    int len = lenList[j].len + 1;
                    if (len > lenList[i].len) {
                        lenList[i].len = len;
                        lenList[i].cnt = lenList[j].cnt;
                    } else if (len == lenList[i].len) {
                        lenList[i].cnt += lenList[j].cnt;
                    }
                }
            }
            if (maxNode.len < lenList[i].len) {
                maxNode.len = lenList[i].len;
                maxNode.cnt = lenList[i].cnt;
            } else if (maxNode.len == lenList[i].len) {
                maxNode.cnt += lenList[i].cnt;
            }
        }
        return maxNode.cnt;
    }
};
}

namespace binary_search {
struct LenNode {
    int value;
    int cnt;
    LenNode(int V) : value(V), cnt(1) {}
    LenNode(int V, int n) : value(V), cnt(n) {}
    LenNode operator+(const LenNode& obj) {
        return LenNode(obj.value, cnt + obj.cnt);
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();
        vector< vector<LenNode> > lenList(1);
        lenList[0].emplace_back(LenNode(INT_MIN));
        auto cmp = [](vector<LenNode>& vec, int x) -> bool {
            return x > vec.back().value;
        };
        for (int i = 0; i < N; i++) {
            if (nums[i] > lenList.back().back().value) {
                lenList.emplace_back();
                Insert(nums[i], lenList.end() - 1);
            } else {
                auto it = lower_bound(lenList.begin(), lenList.end(), nums[i], cmp);
                Insert(nums[i], it);
            }
        }
        auto ret = accumulate(lenList.back().begin(), lenList.back().end(), LenNode(0, 0));
        int cnt = 0;
        for (auto& node : lenList.back()) {
            cnt += node.cnt;
        }
        return ret.cnt;
    }
private:
    void Insert(int value, vector< vector<LenNode> > :: iterator it) {
        auto pre = it - 1;
        int cnt = 0;
        for (auto rIt = pre->rbegin(); rIt != pre->rend(); rIt++) {
            if (rIt->value < value) {
                cnt += rIt->cnt;
                continue;
            }
            break;
        }
        it->emplace_back(LenNode(value, cnt));
    }
};
}

void LC0637Test()
{
    vector<int> nums = {1,3, 2, 8,7,6,9,7,12, 11};
    binary_search::Solution solu;
    cout << solu.findNumberOfLIS(nums) << endl;
}
