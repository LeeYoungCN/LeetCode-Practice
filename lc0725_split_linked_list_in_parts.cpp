/*
 * LeetCode算法练习
 * Description  : LeetCode题库725题, https://leetcode-cn.com/problems/split-linked-list-in-parts/
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
#include "lc0725_split_linked_list_in_parts.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ret(k, nullptr);
        const int N = GetLen(head);
        const int tmpLength = N / k;
        const int remainder = N % k;
        for (int i = 0; i < k && head; i++) {
            int l = tmpLength + (i < remainder ? 1 : 0);
            ret[i] = SplitLenth(head, l);
        }
        return ret;
    }
private:
    int GetLen(ListNode* head)
    {
        int length = 0;
        ListNode* tmpNode = head;
        while (tmpNode) {
            length++;
            tmpNode = tmpNode->next;
        }
        return length;
    }

    ListNode* SplitLenth(ListNode*& root, int length)
    {
        ListNode* retNode = root;
        int l = 0;
        while (l < length) {
            l++;
            ListNode* nextNode = root->next;
            if (l == length) {
                root->next = nullptr;
            }
            root = nextNode;
        }
        return retNode;
    }
};

PrintListNode(ListNode* head) {
    if (head) {
        cout << head->val << ", "
        head = head->next;
    } else {
        cout << "" << endl;
    }
    while(head) {
        cout << head->val;
        cout << ", "
        head = head->next;
    }
    cout << endl;
}