/*
 * LeetCode算法练习
 * Description  : LeetCode题库240题, https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * Author       : 李阳
 * Created      : 2021-09-13
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
#include "lc0240_search_a_2d_matrix_ii.h"

using namespace std;

struct Range {
    int start;
    int end;
    Range(int x, int y) : start(x), end(y) {}
};

struct Bound {
    int upper;
    int lower;
    int equal;
    Bound() : upper(-1), lower(-1), equal(-1) {}
};

enum class Dir {
    ROW,
    COL,
};

class SearchMatrix {
public:
    SearchMatrix(vector<vector<int>>& matrix, int target) : 
    matrix(matrix), target(target), ROW_NUM(matrix.size()), COL_NUM(matrix[0].size()) {}

    bool GetResult()
    {
        Range rowRg(0, ROW_NUM - 1);
        Range colRg(0, COL_NUM - 1);
        Dir dir = Dir::COL;
        Range* changeRange;
        Range* stableRnage;
        while (true) {
            if (dir == Dir::COL) {
                dir = Dir::ROW;
                changeRange = &colRg;
                stableRnage = &rowRg;
            } else {
                dir = Dir::COL;
                changeRange = &rowRg;
                stableRnage = &colRg;
            }

            Bound lowerBound = GetBound(stableRnage->start, changeRange, dir);
            Bound upperBound = GetBound(stableRnage->end,   changeRange, dir); 
            if (upperBound.equal != -1 || lowerBound.equal != -1) {
                return true;
            }
            changeRange->start = upperBound.upper;
            changeRange->end   = lowerBound.lower;
            if (changeRange->start == -1 || changeRange->end == -1 || changeRange->start > changeRange->end) {
                return false;
            }
        }
        return false;
    }
private:
    Bound GetBound(int stableIndex, Range* range, Dir dir) {
        Bound result;
        int start = range->start;
        int end = range->end;
        while (start <= end) {
            int middle = (start + end) / 2;
            int nowValue = 
                (dir == Dir::ROW ? matrix[stableIndex][middle] : matrix[middle][stableIndex]);
            if (nowValue == target) {
                result.equal = middle;
                break;
            } else if (nowValue > target) {
                result.upper = middle;
                end = middle - 1;
            } else {
                result.lower = middle;
                start = middle + 1;
            }
        }
        return result;
    }

    vector<vector<int>>& matrix;
    int target;
    const int ROW_NUM;
    const int COL_NUM;
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        SearchMatrix searchMatrix(matrix, target);
        return searchMatrix.GetResult();
    }
};

void LC0240Test()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    Solution solu;
    auto result = solu.searchMatrix(matrix, target);
    PrintBool(result);
}