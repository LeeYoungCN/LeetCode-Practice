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
        vector<vector<int>> queue;
        map<int, vector<vector<int>>> store;

        for (vector<int> p: people) {
            int sum = accumulate(p.begin(), p.end(), 0);
            store[sum].push_back(p);
        }

        for (auto it = store.begin(); it != store.end(); it ++) {
            vector<vector<int>> v = it->second;
            sort(v.begin(), v.end());
            for (vector<int> a: v) {
                WriteVector<int>(a);
                cout << endl;
            }
            cout << endl;
            
        }

        return people;

    }

    bool compare(vector<int> x, vector<int> y) {
        return x[0] < y[0];
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
    // for (auto v: people) {
    //     WriteVector<int>(v);
    //     cout << endl;
    // }
}