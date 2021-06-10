/*
 * LeetCode算法练习
 * Description  : LeetCode题库1744题，https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
 * Author       : 李阳
 * Created      : 2021-06-01
 * 
 * [1744]你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 * 给你一个下标从 0 开始的正整数数组 candiesCount ，其中 candiesCount[i] 表示你拥有的第 i 类糖果的数目。
 * 同时给你一个二维数组 queries ，其中 queries[i] = [favoriteTypei, favoriteDayi, dailyCapi]。
 * 
 * 你按照如下规则进行一场游戏：
 *      你从第 0 天开始吃糖果
 *      你在吃完 所有 第 i - 1 类糖果之前，不能 吃任何一颗第 i 类糖果。
 *      在吃完所有糖果之前，你必须每天 至少 吃 一颗 糖果。
 * 请你构建一个布尔型数组 answer ，满足 answer.length == queries.length 。
 * answer[i] 为 true 的条件是：在每天吃 不超过 dailyCapi 颗糖果的前提下，你可以在第 favoriteDayi 天吃到第 favoriteTypei 类糖果；
 * 否则 answer[i] 为 false 。注意，只要满足上面 3 条规则中的第二条规则，你就可以在同一天吃不同类型的糖果。
 * 请你返回得到的数组 answer 。
 * 
 */
#include <iostream>
#include <vector>

#include "lc1744_can_you_eat_your_favorite_candy_on_your_favorite_day.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        const int FAVORITE_TYPE = 0; // 最喜欢的糖果类型
        const int FAVORITE_DAY  = 1; // 最喜欢的那天
        const int DAILY_CAP     = 2; // 每天最大消耗量

        const int size          = queries.size();
        const int typeNum       = candiesCount.size();

        vector<long> cntBefore(typeNum); // 在favoriteType之前的糖果的数量
        vector<bool> answer(size);
        for (int j = 1; j < typeNum; j++) {
            cntBefore[j] = cntBefore[j-1] + candiesCount[j-1];
        }

        for (int i = 0; i < size; i++) {
            int favoriteDay  = queries[i][FAVORITE_DAY];
            int favoriteType = queries[i][FAVORITE_TYPE];
            int dailyCap     = queries[i][DAILY_CAP];
            pair<long, long> theoLim;   // 若成立，则前favoriteDay-1天理论上应该消耗的糖果数量范围
            pair<long, long> pracLim;   // 实际favoriteDay-1天消耗的糖果数量范围

            pracLim.first  = favoriteDay; // 每天消耗1个
            pracLim.second = dailyCap * pracLim.first; // 每天消耗dailyCap个

            theoLim.first  = cntBefore[favoriteType] - (dailyCap - 1);
            theoLim.second = cntBefore[favoriteType] + (candiesCount[favoriteType] - 1);

            answer[i] = !(pracLim.second < theoLim.first || pracLim.first > theoLim.second);
        }
        return answer;
    }
};

void LC1744Test(void)
{
    const int QUERY_SIZE = 3;
    const int candyTypeNum = ReadInt();
    vector<int> candiesCount = ReadVector<int>(candyTypeNum);

    const int queryNum = ReadInt();
    vector<vector<int>> queries;
    for (int i = 0; i < queryNum; i++) {
        queries.push_back(ReadVector<int>(QUERY_SIZE));
    }

    Solution solu;

    vector<bool> answer = solu.canEat(candiesCount, queries);
    WriteBoolVector(answer);
}