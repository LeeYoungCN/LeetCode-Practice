/*
 * LeetCode算法练习
 * Description   : LeetCode题库225题, https://leetcode-cn.com/problems/implement-stack-using-queues/
 * Author        : 李阳
 * Created       : 2022-02-19 12:25:47
 */

#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

#include "gtest/gtest.h"
#include "lc0225_implement_stack_using_queues.h"

using namespace std;

#define ITEM_OF(arr) sizeof(arr) / sizeof(arr[0])

typedef unsigned           int UINT32;
typedef                    int SINT32;
typedef unsigned long long int UINT64;

class MyStack {
public:
    MyStack() {
        this->m_queueVec = vector<queue<int>> (2, queue<int>());
        this->m_topNum = 0;
        this->m_storeNum = 1;
    }
    
    void push(int x) {
        if (!m_queueVec[m_topNum].empty()) {
            m_queueVec[m_storeNum].push(m_queueVec[m_topNum].front());
            m_queueVec[m_topNum].pop();
        }
        m_queueVec[m_topNum].push(x);
    }
    
    int pop() {
        if (this->empty()) {
            return INT_MIN;
        }
        if (m_queueVec[m_topNum].empty()) {
            TransQue();
        }
        SINT32 tmp = m_queueVec[m_topNum].front();
        m_queueVec[m_topNum].pop();
        return tmp;
    }
    
    int top() {
        if (this->empty()) {
            return INT_MIN;
        }
        if (m_queueVec[m_topNum].empty()) {
            TransQue();
        }
        return m_queueVec[m_topNum].front();
    }
    
    bool empty() {
        return m_queueVec[m_topNum].empty() && m_queueVec[m_storeNum].empty();
    }
private:
    void TransQue()
    {
        if (m_queueVec[m_storeNum].empty() || !m_queueVec[m_topNum].empty()) {
            return;
        }
        const UINT64 len = m_queueVec[m_storeNum].size();
        for (UINT64 i = 0; i < len - 1; i++) {
            m_queueVec[m_topNum].push(m_queueVec[m_storeNum].front());
            m_queueVec[m_storeNum].pop();
        }
        m_storeNum = 1 - m_storeNum;
        m_topNum   = 1 - m_topNum;
    }
    vector<queue<SINT32>> m_queueVec;
    UINT32 m_topNum;
    UINT32 m_storeNum;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class LC0225TestCase : public testing::Test {
protected:
    void SetUp() {
        testStack = MyStack();
        rightVec = vector<SINT32>();
    };
    void TearDown() {};

    void TEST_EMPTY()
    {
        EXPECT_EQ(rightVec.empty(), testStack.empty());
    }

    void TEST_PUSH(const vector<SINT32>& testVec)
    {
        for (const SINT32& num : testVec) {
            testStack.push(num);
            rightVec.push_back(num);
            EXPECT_EQ(num, testStack.top());
            EXPECT_EQ(rightVec.back(), testStack.top());
        }
    }

    void TEST_POP(const vector<SINT32>& testVec)
    {
        TEST_PUSH(testVec);
        while(!rightVec.empty()) {
            EXPECT_EQ(rightVec.back(), testStack.pop());
            rightVec.pop_back();
        }
        TEST_EMPTY();
    }

    MyStack testStack;
    vector<SINT32> rightVec;
};

TEST_F(LC0225TestCase, EMPTY)
{
    TEST_EMPTY();
}

TEST_F(LC0225TestCase, PUSH)
{
    const SINT32 testCase[] = {
        1, 2, 3, 4, 5
    };
    TEST_PUSH(vector<SINT32>(testCase, testCase + ITEM_OF(testCase)));
}

TEST_F(LC0225TestCase, POP)
{
    const SINT32 testCase[] = {
        1, 2, 3, 4, 5
    };
    TEST_POP(vector<SINT32>(testCase, testCase + ITEM_OF(testCase)));
}

int LC0225Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

