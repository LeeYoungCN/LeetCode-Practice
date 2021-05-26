/*
 * LeetCode算法练习
 * Description  : LeetCode题库621题，https://leetcode-cn.com/problems/task-scheduler/
 * Author       : 李阳
 * Created      : 2021-05-20
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#include "public_function.h"
#include "lc0621_task_scheduler.h"

using namespace std;

typedef struct{
    int nextTime;
    int cnt;
} Priority;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        int total = tasks.size();
        vector<char> scheduler;
        unordered_map<char,Priority> taskMap;
        for (char t: tasks) {
            taskMap[t].cnt++;
        }

        while (total) {
            char nextTask = '\0';
            for (auto task: taskMap) {
                if (task.second.nextTime <= time && task.second.cnt > 0 &&
                    (nextTask == '\0' || task.second.cnt > taskMap[nextTask].cnt)) {
                    nextTask = task.first;
                }               
            }
            if (nextTask) {
                taskMap[nextTask].cnt--;
                taskMap[nextTask].nextTime += (n+1);
                scheduler.push_back(nextTask);
                total--;
                // if (taskMap[nextTask].cnt == 0) {
                //     taskMap.erase(nextTask);
                // }
            }
            time++;
        }
        WriteVector(scheduler);
        cout << endl;
        return time;
    }
};

void LC0621Test(void)
{
    int N = ReadInt();
    vector<char> tasks = ReadVector<char>(N);
    int n = ReadInt();

    Solution solu;

    cout << solu.leastInterval(tasks, n) << endl;
}