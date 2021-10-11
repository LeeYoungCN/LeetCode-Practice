/*
 * LeetCode算法练习
 * Description   : LeetCode题库273题, https://leetcode-cn.com/problems/integer-to-english-words/
 * Author        : 李阳
 * Created       : 2021-10-11 19:54:06
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
#include "lc0273_integer_to_english_words.h"

using namespace std;

namespace {
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        int mod = 1'000'000'000;
        string ret = "";
        deque<string> strQue;
        for (int i = 0; i < 4; i++) {
            int tmp = num / mod;
            string curr = "";
            Num2Str(curr, tmp);
            num %= mod;
            mod /= 1000;
            if (curr.empty()) {
                continue
;            }
            ret += curr + quantityStr[i] + " ";
            
        }
        while (ret.back() == ' ') {
            ret.pop_back();
        }
        return ret;
    }
private:
    void Num2Str(string& curr, int num)
    {
        string ret = "";
        if (num == 0) {
            return;
        } else if (num < 10) {
            curr += ones[num] + " ";
        } else if (num < 20) {
            curr += teen[num - 10] + " ";
        } else if (num < 100) {
            curr += tens[num/10] + " ";
            Num2Str(curr, num%10);
        } else {
            curr += ones[num/100] + " Hundred ";
            Num2Str(curr, num%100);
        }
    }
    vector<string> ones = {
        "",         "One",      "Two",          "Three",    "Four",
        "Five",     "Six",      "Seven",        "Eight",    "Nine"
    };
    vector<string> teen = {
        "Ten",      "Eleven",   "Twelve",       "Thirteen", "Fourteen",
        "Fifteen",  "Sixteen",  "Seventeen",    "Eighteen", "Nineteen"
    };
    vector<string> tens = {
        "",         "Ten",      "Twenty",       "Thirty",   "Forty",
        "Fifty",    "Sixty",    "Seventy",      "Eighty",   "Ninety"
    };

    vector<string> quantityStr {
        "Billion",  "Million",  "Thousand", "",
    };
};

Solution solu;

TEST(WordTest, ZERO)
{
    vector<pair<int, string>> testCase {
        {0,  "Zero"},
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}

TEST(WordTest, ONE)
{
    vector<pair<int, string>> testCase {
        {1,  "One"},        {2,  "Two"},        {3,  "Three"},      {4,  "Four"},   {5,  "Five"}, 
        {6,  "Six"},        {7,  "Seven"},      {8,  "Eight"},      {9,  "Nine"},
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}

TEST(WordTest, TEN)
{
    vector<pair<int, string>> testCase {
        {10, "Ten"},        {11, "Eleven"},     {12, "Twelve"},     {13, "Thirteen"},   {14, "Fourteen"},
        {15, "Fifteen"},    {16, "Sixteen"},    {17, "Seventeen"},  {18, "Eighteen"},   {19, "Nineteen"},
        {20, "Twenty"},     {33, "Thirty Three"}, {44, "Forty Four"}, {55, "Fifty Five"}, {66, "Sixty Six"},
        {77, "Seventy Seven"}, {88, "Eighty Eight"}, {99, "Ninety Nine"}
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}

TEST(WordTest, HUNDRED)
{
    vector<pair<int, string>> testCase {
        {100,  "One Hundred"}, {202, "Two Hundred Two"}, {415, "Four Hundred Fifteen"},
        {550, "Five Hundred Fifty"}, {681, "Six Hundred Eighty One"}
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}

TEST(WordTest, THOUSAND)
{
    vector<pair<int, string>> testCase {
        {1000,  "One Thousand"}, {2002,  "Two Thousand Two"}, {3033,  "Three Thousand Thirty Three"}, {5511, "Five Thousand Five Hundred Eleven"},
        {12001, "Twelve Thousand One"}, {503120, "Five Hundred Three Thousand One Hundred Twenty"},
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}

TEST(WordTest, MILLION)
{
    vector<pair<int, string>> testCase {
        {1'000'000, "One Million"}, {15'001'015, "Fifteen Million One Thousand Fifteen"},
        {50'502'895, "Fifty Million Five Hundred Two Thousand Eight Hundred Ninety Five"}
    };
    for (auto& [input, rightRst] : testCase) {
        EXPECT_EQ(rightRst, solu.numberToWords(input));
    }
}
}

int LC0273Test(int argc, char** argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

