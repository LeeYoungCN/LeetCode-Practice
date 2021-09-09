/*
 * LeetCode算法练习
 * Description  : LeetCode题库68题, https://leetcode-cn.com/problems/text-justification/submissions/
 * Author       : 李阳
 * Created      : 2021-09-09
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

#include "public_function.h"
#include "lc0068_text_justification.h"

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int charWidth = 0;
        const int N = words.size();
        auto it  = words.begin();
        auto end = words.end();
        int wordNum = 0;
        int i = 0;
        while (i < N) {
            int newWordWidth = words[i].size();
            int minLineWidth = charWidth + newWordWidth + wordNum;
            if (minLineWidth <= maxWidth) {
                charWidth += newWordWidth;
                wordNum++;
                i++;
                continue;
            }

            result.emplace_back(AlignBothEndsStr(wordNum, charWidth, maxWidth, it, end));
            charWidth = 0;
            wordNum = 0;
        }
        result.emplace_back(AlignLeftEndStr(wordNum,charWidth, maxWidth, it, end));

        return result;
    }
private:
    string AlignBothEndsStr(int wordNum, int charWidth, int maxWidth, vector<string>::iterator &it, vector<string>::iterator &end)
    {
        deque<int> spaceNumQue;
        int totalSpcaeNum = maxWidth - charWidth; // 需要空格的总量
        int gapNum = max(wordNum - 1, 1); // 单词之间，间隔的数量，当wordNum == 1时，word后面至少有一段间隔
        string ret;

        // 计算各间隔内的空格数量，从后往前计算，计算结果保存在数组中
        while(gapNum > 0) {
            int spaceNum = totalSpcaeNum / gapNum;
            spaceNumQue.emplace_front(spaceNum);
            totalSpcaeNum -= spaceNum;
            gapNum--;
        }
        // 两端对齐场景，单词数量>=间隔数量,已单词+间隔的形式将结果保存
        for (int spaceNum : spaceNumQue) {
            ret += *it;
            ++it;
            ret += string(spaceNum, ' ');
        }
        // 只有一个单词的场景，末尾不存在单词，不增加单词
        if (wordNum > 1) {
            ret += *it;
            ++it;
        }
        return ret;
    }

    string AlignLeftEndStr(int wordNum, int charWidth, int maxWidth, vector<string>::iterator &it, vector<string>::iterator &end)
    {
        string ret;
        int gapNum =  wordNum - 1; // 单词间间隔的数量
        int endSpaceNum = maxWidth - charWidth - gapNum;
        ret += *it;
        ++it;
        while(it != end) {
            ret += " ";
            ret += *it;
            ++it;
        }
        ret += string(endSpaceNum, ' ');
        return ret;
    }
};

void LC0068Test()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    Solution solu;
    auto result = solu.fullJustify(words, maxWidth);
    WriteVector<string>(result, ",\n");
}