/*
 * LeetCode算法练习
 * Description   : LeetCode题库187题, https://leetcode-cn.com/problems/repeated-dna-sequences/
 * Author        : 李阳
 * Created       : 2021-11-13 22:10:06
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

#include "gtest/gtest.h"
#include "lc0187_repeated_dna_sequences.h"

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int L = 10;
        const int N = s.size();
        vector<string> ans;
        unordered_map<string, int> visit;
        for (int i = 0; i <= N - L; i++) {
            string subStr = s.substr(i, L);
            if(++visit[subStr] == 2) {
                ans.emplace_back(subStr);
            }
        }
        return ans;
    }
};

class LC0187TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void TestFunc(vector<string> rightRst, const string &input)
    {
        vector<string> output = solu.findRepeatedDnaSequences(input);
        EXPECT_EQ(rightRst, output);
    }

    Solution solu;
};

TEST_F(LC0187TestCase, LowerTen)
{
    TestFunc({}, "");
    TestFunc({"AAAAAAAAAA"}, "AAAAAAAAAAA");
    TestFunc({"AAAAACCCCC", "CCCCCAAAAA"},
            "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
}

int LC0187Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

