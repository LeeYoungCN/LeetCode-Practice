/*
 * LeetCode算法练习
 * Description  : LeetCode题库297题, https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 * Author       : 李阳
 * Created      : 2021-06-30
 *
 * [297]二叉树的序列化与反序列化
 *
 *
 *https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 示例: 
 * 你可以将以下二叉树：
 * 
 *     1
 *    / \
 *   2   3
 *      / \
 *     4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <unordered_map>

#include "lc0297_serialize_and_deserialize_binary_tree.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        deque<TreeNode *> bfsQue;
        bfsQue.push_back(root);

        while (!bfsQue.empty()) {
            TreeNode* node = bfsQue.front();
            bfsQue.pop_front();

            if (node) {
                ret += to_string(node->val) + ',';
            }else {
                ret += "null,";
                continue;
            }
            bfsQue.push_back(node->left);
            bfsQue.push_back(node->right);
        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string::iterator it = data.begin();
        deque<TreeNode *> bfsQue;        
        TreeNode* root = CreateNode(it);

        bfsQue.push_back(root);

        while (it != data.end()) {
            TreeNode* node = bfsQue.front();
            bfsQue.pop_front();

            if (node == NULL) {
                continue;
            }

            bfsQue.push_back(node->left = CreateNode(it));
            bfsQue.push_back(node->right = CreateNode(it));
        }
        return root;
    }

private:
    string GetStr(string::iterator& it)
    {
        string tmp = "";
        while(*it != ',') {
            tmp += *(it++);
        }
        it++;
        return tmp;
    }

    TreeNode* CreateNode(string::iterator& it)
    {
        TreeNode* node = NULL;
        string str = GetStr(it);
        if (str != "null") {
            node = new TreeNode(Str2Int(str));
        }
        return node;
    }

    int Str2Int(string data)
    {
        int ret = 0;
        int sign = 1;
        const int N = data.size();

        for (int i = 0; i < N; i++) {
            char c = data[i];
            if(i == 0 && c == '-') {
                sign = -1;
                continue;
            }
            if (c < '0' || c > '9') {
                return INT_MIN;
            }
            ret = ret * 10 + (c - '0');
        }
        return sign*ret;
    }
};

void LC0297Test()
{
    string data = "1,2,3,3,null,";
    Codec solu;
    TreeNode* root = solu.deserialize(data);
    cout << solu.serialize(root) << endl;
}
