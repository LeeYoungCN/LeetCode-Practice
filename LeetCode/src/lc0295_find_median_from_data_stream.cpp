/*
 * LeetCode算法练习
 * Description  : LeetCode题库295题, https://leetcode-cn.com/problems/find-median-from-data-stream/
 * Author       : 李阳
 * Created      : 2021-08-29
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
#include "lc0295_find_median_from_data_stream.h"

using namespace std;

struct DNode {
    int value;
    DNode* before;
    DNode* next;
    DNode(int val):value(val),before(nullptr),next(nullptr) {};
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder():left(nums.end()),right(nums.end()),size(0) {

    }
    
    void addNum(int num) {
        size++;
        nums.insert(num);
        if (size == 1) {
            left = nums.begin();
            right = nums.begin();
            return;
        }

        if (size % 2 == 0) { // 奇数变偶数
            if (num >= *left) {
                right++;
            } else {
                left--;
            }
        } else { // 偶数变奇数
            if (num >= *right) {
                left++;
            } else if (num < *left) {
                right--;
            } else {
                left++;
                right--;
            }
        }

    }

    double findMedian() {
        double num1 = *left;
        double num2 = *right;
        return (num1 + num2) / 2;
    }

private:
    multiset<int> nums;
    multiset<int>::iterator left;
    multiset<int>::iterator right;
    size_t size;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

void LC0295Test()
{
    MedianFinder solu;
    solu.addNum(1);
    cout << solu.findMedian() << endl;
    solu.addNum(2);
    cout << solu.findMedian() << endl;
}