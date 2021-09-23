/*
 * LeetCode算法练习
 * Description  : LeetCode题库430题, https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
 * Author       : 李阳
 * Created      : 2021-09-24
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
#include "lc0430_flatten_a_multilevel_doubly_linked_list.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* tmpNode = head;
        Node* nextNode = nullptr;
        vector<Node*> nodeStack;
        while(tmpNode || !nodeStack.empty()) {
            if (tmpNode->child) {
                if (tmpNode->next) {
                    nodeStack.emplace_back(tmpNode->next);
                }
                nextNode = tmpNode->child;
                tmpNode->child = nullptr;
            } else if (tmpNode->next){
                nextNode = tmpNode->next;
            } else {
                if (nodeStack.empty()) {
                    break;
                }
                nextNode = nodeStack.back();
                nodeStack.pop_back();
            }
            tmpNode->next = nextNode;
            nextNode->prev = tmpNode;
            tmpNode = nextNode;
        }
        return head;
    }
};

void LC0430Test()
{
    ;
}