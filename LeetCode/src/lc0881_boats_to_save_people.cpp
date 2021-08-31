/*
 * LeetCode算法练习
 * Description  : LeetCode题库881题, https://leetcode-cn.com/problems/boats-to-save-people/
 * Author       : 李阳
 * Created      : 2021-08-28
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0881_boats_to_save_people.h"

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        const int N = people.size();
        sort(people.begin(), people.end());
        int left = 0;
        int right = N - 1;
        int cnt = 0;
        while (left<=right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            cnt++;
        }
        return cnt;
    }
};

void LC0881Test()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    Solution solu;
    cout << solu.numRescueBoats(people, limit) << endl;
}