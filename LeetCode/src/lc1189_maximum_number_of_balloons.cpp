/*
 * LeetCode算法练习
 * Description   : LeetCode题库1189题, https://leetcode-cn.com/problems/maximum-number-of-balloons/
 * Author        : 李阳
 * Created       : 2022-02-13 16:27:21
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
#include "lc1189_maximum_number_of_balloons.h"

using namespace std;

struct CharInfoSt {
    int base;
    int cnt;
};

const char *TARGET_STR = "balloon";

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if (text.size() == 0) {
            return 0;
        }
        int num = INT_MAX;
        Init();
        for (const char& c : text) {
            if (cntMap.count(c)) {
                ++cntMap[c].cnt;
            }
        }
        for (const auto&[c, charInfo] : cntMap) {
            num = min(num, charInfo.cnt/charInfo.base);
        }
        return num;
    }
private:
    void Init()
    {
        for (const char *p = TARGET_STR; *p != '\0'; p++) {
            if (cntMap.count(*p)) {
                cntMap[*p].base++;
            } else {
                cntMap.emplace(*p, CharInfoSt{1, 0});
            }
        }
    }

    unordered_map<char, CharInfoSt> cntMap;
};

struct TestCase {
    string text;
    int rightAnswer;
};

class LC1189TestCase : public testing::Test {
protected:
    void SetUp() {};
    void TearDown() {};

    void TestFunc(vector<TestCase> testCaseVec)
    {
        for (const auto& testCase : testCaseVec) {
            Solution solu;
            EXPECT_EQ(
                solu.maxNumberOfBalloons(testCase.text),
                testCase.rightAnswer
            ) << "test case = " << testCase.text;
        }
    }
};

TEST_F(LC1189TestCase, test)
{
    vector<TestCase> testCaseVec = {
        //{"balloon", 1},
        //{"balloo", 0},
        {"nlaebolko", 1},
        {"loonbalxballpoon", 2},
        //{"123", 0}
    };
    TestFunc(testCaseVec);
}

int LC1189Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

