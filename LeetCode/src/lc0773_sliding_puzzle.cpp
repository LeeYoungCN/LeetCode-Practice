/*
 * LeetCode算法练习
 * Description  : LeetCode题库773题，https://leetcode-cn.com/problems/sliding-puzzle/description/
 * Created      : 2021-06-27
 *
 * [773]滑动谜题
 *
 *
 *https://leetcode-cn.com/problems/sliding-puzzle/description/
 *
 *
 * 在一个 2 x 3 的板上（board）有 5 块砖瓦，用数字 1~5 来表示, 以及一块空缺用 0 来表示.
 * 一次移动定义为选择 0 与一个相邻的数字（上下左右）进行交换.
 * 最终当板 board 的结果是 [[1,2,3],[4,5,0]] 谜板被解开。
 * 给出一个谜板的初始状态，返回最少可以通过多少次移动解开谜板，如果不能解开谜板，则返回 -1 。
 * 示例：
 * 
 * 输入：board = [[1,2,3],[4,0,5]]
 * 输出：1
 * 解释：交换 0 和 5 ，1 步完成
 * 
 * 
 * 输入：board = [[1,2,3],[5,4,0]]
 * 输出：-1
 * 解释：没有办法完成谜板
 * 
 * 
 * 输入：board = [[4,1,2],[5,0,3]]
 * 输出：5
 * 解释：
 * 最少完成谜板的最少移动次数是 5 ，
 * 一种移动路径:
 * 尚未移动: [[4,1,2],[5,0,3]]
 * 移动 1 次: [[4,1,2],[0,5,3]]
 * 移动 2 次: [[0,1,2],[4,5,3]]
 * 移动 3 次: [[1,0,2],[4,5,3]]
 * 移动 4 次: [[1,2,0],[4,5,3]]
 * 移动 5 次: [[1,2,3],[4,5,0]]
 * 
 * 
 * 输入：board = [[3,2,4],[1,5,0]]
 * 输出：14
 * 
 * 提示：
 * 
 * board 是一个如上所述的 2 x 3 的数组.
 * board[i][j] 是一个 [0, 1, 2, 3, 4, 5] 的排列.
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

#include "lc0773_sliding_puzzle.h"

using namespace std;

typedef struct{
    string status;
    int pos;
    int step;
} Node;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        const int R = 2;
        const int C = 3;

        unordered_set<string> visit;
        deque<Node> bfsQueue;
        string target = "123450";
        Node nodeNow = {"", 0, 0};

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int num = board[i][j];
                if (num == 0) {
                    nodeNow.pos = i * C + j;
                }
                nodeNow.status += (num + '0');
            }
        }
        
        visit.insert(nodeNow.status);
        bfsQueue.push_back(nodeNow);
        while (!bfsQueue.empty()) {
            nodeNow = bfsQueue.front();
            bfsQueue.pop_front();
            if (nodeNow.status == target) {
                return nodeNow.step;
            }
            vector<int> dir = dirs[nodeNow.pos];
            int nextStep = nodeNow.step + 1;
            for (int d: dir) {
                string nextStatus = NextStatus(nodeNow.status, nodeNow.pos, d);
                
                if (visit.find(nextStatus) != visit.end()) {
                    continue;
                }

                Node nodeNext = {nextStatus, d, nextStep};
                bfsQueue.push_back(nodeNext);
                visit.insert(nextStatus);
            }
        }
        return -1;
    }

private:
    string NextStatus(string status, int zeroPos, int dir)
    {
        status[zeroPos] = status[dir];
        status[dir] = '0';
        return status;
    }

    const vector<vector<int>> dirs = {
        {1, 3}, {0, 2, 4}, {1, 5}, 
        {0, 4}, {1, 3, 5}, {2, 4}
    };
};


void LC0773Test()
{
    ;
}