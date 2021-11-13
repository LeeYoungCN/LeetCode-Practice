/*
 * LeetCode算法练习
 * Description   : LeetCode题库520题, https://leetcode-cn.com/problems/detect-capital/
 * Author        : 李阳
 * Created       : 2021-11-13 09:05:45
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
#include "lc0520_detect_capital.h"

using namespace std;

enum Pattern : unsigned int{
    LOWER,
    UPPER,
};

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1) {
            return true;
        }
        Pattern pattern = LOWER;
        if (IsUpper(word[0]) && IsUpper(word[1])) {
            pattern = UPPER;
        }
        const size_t N = word.size();
        for (size_t i = 1; i < N; i++) {
            if (pattern == LOWER && IsUpper(word[i])) {
                return false;
            }
            if (pattern == UPPER && !IsUpper(word[i]))
            {
                return false;
            }
        }
        return true;
    }
private:
    bool IsUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
};

class LC0502TestCase : public testing::Test {
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    void TestTrue(vector<string> testCase)
    {
        for (const string& testStr : testCase) {
            EXPECT_TRUE(solu.detectCapitalUse(testStr));
        }
    }

    void TestFalse(vector<string> testCase)
    {
        for (const string& testStr : testCase) {
            EXPECT_FALSE(solu.detectCapitalUse(testStr));
        }
    }
    Solution solu;
};

TEST_F(LC0502TestCase, SizeOne)
{
    vector<string> testTrueCase = {
        "A", "a"
    };
    TestTrue(testTrueCase);
}

TEST_F(LC0502TestCase, AllLoewr)
{
    vector<string> testTrueCase = {
        "ab", "abcd",
    };
    vector<string> testFalseCase = {
        "aAc", "aBBB", "cdaA"
    };
    TestTrue(testTrueCase);
    TestFalse(testFalseCase);
}

TEST_F(LC0502TestCase, AllUpper)
{
    vector<string> testTrueCase = {
        "AB", "ABCD",
    };
    vector<string> testFalseCase = {
        "AACs", "ABc", "ABCDe"
    };
    TestTrue(testTrueCase);
    TestFalse(testFalseCase);
}

TEST_F(LC0502TestCase, Mix)
{
    vector<string> testTrueCase = {
        "Ab", "Abcde",
    };
    vector<string> testFalseCase = {
        "AbcD", "AccvSvd", "ABCsc"
    };
    TestTrue(testTrueCase);
    TestFalse(testFalseCase);
}

int LC0520Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

