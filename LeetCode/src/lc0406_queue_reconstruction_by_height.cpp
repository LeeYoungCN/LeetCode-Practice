/*
 * LeetCode算法练习
 * Description  : LeetCode题库406题，https://leetcode-cn.com/problems/queue-reconstruction-by-height/
 * Author       : 李阳
 * Created      : 2021-05-17
 */
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

#include "lc0406_queue_reconstruction_by_height.h"
#include "public_function.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = static_cast<int>(people.size());
        vector<vector<int>> queue(N);
        
        sort(people.begin(), people.end(), [](const vector<int> &x, const vector<int> &y) {
            return (x[0] < y[0]) || (x[0] == y[0] && x[1] > y[1]);
        });
        for (vector<int> person: people) {
            int space = 0;
            for (int i = 0; i< N; i++) {
                if (queue[i].empty()) {
                    if (space == person[1]) {
                        queue[i] = person;
                        break;
                    } else {
                        space++;
                    }
                }
            }
        }
        return queue;
    }
};

void LC0406Test(void)
{
    const int N = 2;
    int num = ReadInt();
    vector<vector<int>> people(num, vector<int>(N, 0));
    
    for (int i = 0; i < num; i++) {
        people.push_back(ReadVector<int>(2));
    }

    Solution solu;
    people = solu.reconstructQueue(people);
    for (auto v: people) {
        cout << "[";
        WriteVector<int>(v, ", ");
        cout << "]" << endl;
    }
}