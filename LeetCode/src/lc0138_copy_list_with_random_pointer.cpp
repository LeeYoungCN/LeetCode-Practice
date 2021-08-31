/*
 * LeetCode算法练习
 * Description  : LeetCode题库138题, https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 * Author       : 李阳
 * Created      : 2021-07-025
 */
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <climits>

#include "public_function.h"
#include "lc0138_copy_list_with_random_pointer.h"

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* srcNode = head;
        Node* dstHead = new Node(0);
        Node* tmpNode = dstHead;
        unordered_map<Node*, int> srcMap;
        vector<Node *> srcVec;
        vector<Node *> dstVec;
        int N = 0;
        while (srcNode) {
            Node* newNode = copyNode(srcNode);
            srcVec.emplace_back(srcNode);
            srcMap[srcNode] = N++;

            tmpNode->next = newNode;
            dstVec.emplace_back(newNode);
            tmpNode = tmpNode->next;
            srcNode = srcNode->next;
        }

        tmpNode = dstHead->next;

        for (int i = 0; i < N; i++) {
            Node* srcRdmNode = srcVec[i]->random;
            if (srcRdmNode == NULL) {
                continue;
            }

            int rndNum = srcMap[srcRdmNode];
            dstVec[i]->random = dstVec[rndNum];
        }

        return dstHead->next;
    }
private:
    Node* copyNode(Node* srcNode)
    {
        Node* retNode = NULL;
        if (srcNode) {
            retNode = new Node(srcNode->val);
        }
        return retNode;
    }
};

void LC0138Test()
{
    ;
}