/*
 * LeetCode算法练习
 * Description  : LeetCode题库1305题, https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
 * Author       : 李阳
 * Created      : 2021-09-22
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
#include "lc1305_all_elements_in_two_binary_search_trees.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BstIterator {
public:
    BstIterator(TreeNode* root) : root(root) {
        vector<TreeNode*> elmtStack;
        TreeNode* tmpNode = this->root;
        while(tmpNode || !elmtStack.empty()) {
            if (tmpNode == nullptr) {
                tmpNode = elmtStack.back();
                elmtStack.pop_back();
                elmtQue.emplace_back(tmpNode->val);
                tmpNode = tmpNode->right;
            } else {
                elmtStack.emplace_back(tmpNode);
                tmpNode = tmpNode->left;
            }
        }
    }
    bool HasNext() {
        return !elmtQue.empty();
    }

    int Next() {
        int ret = elmtQue.front();
        elmtQue.pop_front();
        return ret;
    }

    int Min() {
        return elmtQue.front();
    }
private:
    TreeNode* root;
    deque<int> elmtQue;
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        BstIterator bt1(root1);
        BstIterator bt2(root2);
        vector<int> ret;
        while(bt1.HasNext() && bt2.HasNext()) {
            if (bt1.Min() <= bt2.Min()) {
                ret.emplace_back(bt1.Next());
            } else {
                ret.emplace_back(bt2.Next());
            }
        }
        BstIterator& bt = bt1.HasNext() ? bt1 : bt2;
        while (bt.HasNext()) {
            ret.emplace_back(bt.Next());
        }
        return ret;
    }
};

void LC0725Test()
{}