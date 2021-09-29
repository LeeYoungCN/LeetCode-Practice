/*
 * LeetCode算法练习
 * Description  : LeetCode题库437题, https://leetcode-cn.com/problems/path-sum-iii/
 * Author       : 李阳
 * Created      : 2021-09-28
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
#include "lc0437_path_sum_iii.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int cnt = 0;
        unordered_map<int, int> tmpMap;
        tmpMap.insert({0, 1});
        if (root) {
            Dfs(root, targetSum, 0, tmpMap, cnt);
        }
        return cnt;
    }
private:
    void Dfs(TreeNode* root, int targetSum, int nowSum, unordered_map<int, int> &tmpMap, int &cnt)
    {
        nowSum += root->val;
        int targetNum = nowSum - targetSum;
        if (tmpMap.count(targetNum)) {
            cnt += tmpMap[targetNum];
        }
        if (tmpMap.count(nowSum)) {
            tmpMap[nowSum]++;
        } else {
            tmpMap.insert({nowSum, 1});
        }
        
        if (root->left) {
            Dfs(root->left, targetSum, nowSum, tmpMap, cnt);
        }
        if (root->right) {
            Dfs(root->right, targetSum, nowSum, tmpMap, cnt);
        }
        if (tmpMap[nowSum] > 1) {
            tmpMap[nowSum]--;
        }else {
            tmpMap.erase(nowSum);
        }
    }
};

void LC0437Test()
{
    ;
}