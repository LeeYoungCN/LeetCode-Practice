/*
 * LeetCode算法练习
 * Description   : LeetCode题库284题, https://leetcode-cn.com/problems/peeking-iterator/
 * Author        : 李阳
 * Created       : 2021-10-05 11:23:07
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0284_peeking_iterator.h"
using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
*/
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    explicit PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        flag = Iterator::hasNext();
        if (flag) {
            nextNum = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextNum;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int tmp = nextNum;
        flag = Iterator::hasNext();
        if (flag) {
            nextNum = Iterator::next();
        }
        return tmp;
    }

    bool hasNext() const {
        return flag;
    }
private:
    bool flag = true;
    int nextNum;
};

void LC0284Test()
{
    ;
}