/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库94题，https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * Author       : 李阳 l0050626
 * Created      : 2021-05-14
 */
#include <iostream>
#include <vector>
#include "lc0094_binary_tree_inorder_traversal.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return ret;
        }

        if (root->left != nullptr) {
            inorderTraversal(root->left);
        }
            ret.push_back(root->val);
        if (root->right != nullptr) {
            inorderTraversal(root->right);
        }
        
        return ret;
    }
private:
    vector<int> ret;
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> nodeStore;

        while (!(nodeStore.empty()) || root != nullptr) {
            if (root->left != nullptr) {
                nodeStore.push_back(root);
                root = root->left;
            } else {
                ret.push_back(root->val);
                if (root-> right != nullptr) {
                    root = root->right;
                } else {
                    if (nodeStore.empty()) {
                        root = nullptr;
                    } else {
                        root = nodeStore.back();
                        root->left = nullptr;
                        nodeStore.pop_back();
                    }
                }
            }
        }
        return ret;
    }
};

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<TreeNode*> nodeStore;

        while (!(nodeStore.empty()) || root != nullptr) {
            if (root == nullptr) {
                root = nodeStore.back();
                nodeStore.pop_back();
                ret.push_back(root->val);
                root = root->right;
            } else {
                nodeStore.push_back(root);
                root = root->left;
            }
        }
        return ret;
    }
};