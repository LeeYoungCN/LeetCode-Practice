/*
 * LeetCode算法练习
 * Description  : LeetCode题库405题, https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/
 * Author       : 李阳
 * Created      : 2021-10-02
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
#include <numeric>

#include "public_function.h"
#include "lc0405_convert_a_number_to_hexadecimal.h"

using namespace std;
namespace mod_method {
#define ONE_SIZE 4
#define HEX_SIZE 32
#define HEX_MOD 16

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        const int LEN = HEX_SIZE / ONE_SIZE;
        vector<int> hexNum(LEN);
        bool isNegative = (num < 0);
        num = abs(num);
        for (int i = 0; i < LEN && num > 0; i++) {
            hexNum[i] = num % HEX_MOD;
            num = num / HEX_MOD;
        }
        if (isNegative) {
            IntToComplement(hexNum);
        }
        return IntVecToHexStr(hexNum);
    }
private:
    void IntToComplement(vector<int>& hexNum)
    {
        int nextNum = 1;
        for (int i = 0; i < HEX_SIZE / ONE_SIZE; i++) {
            hexNum[i] = HEX_MOD - hexNum[i] - 1 + nextNum;
            if (hexNum[i] == HEX_MOD) {
                hexNum[i] = 0;
                nextNum = 1;
            } else {
                nextNum = 0;
            }
        }
    }

    string IntVecToHexStr(vector<int>& hexNum)
    {
        const int N = hexNum.size();
        string ret;
        int i = N -1;
        while (i >= 0 && hexNum[i] == 0) {
            i--;
        }
        while (i >= 0) {
            ret += int2HexStr[hexNum[i]];
            i--;
        }
        return ret;
    }

    unordered_map<int, string> int2HexStr = {
        {0, "0"},  {1, "1"},  {2, "2"},  {3, "3"},
        {4, "4"},  {5, "5"},  {6, "6"},  {7, "7"},
        {8, "8"},  {9, "9"},  {10, "a"}, {11, "b"},
        {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"}
    };
};
}

namespace dgt_method {
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        const int N = 8;
        const int MOV_LEN = 4;
        string ret;
        for (int i = N -1; i >= 0; i--) {
            int tmpVal = (num >> (i * MOV_LEN) & 0xf);
            if (ret.length() > 0 || tmpVal > 0) {
                ret += (tmpVal < 10 ? tmpVal + '0': tmpVal - 10 + 'a');
            }
        }
        return ret;
    }
};
}
void LC0405Test()
{
    using namespace dgt_method;
    int num = -1;
    Solution solu;
    cout << solu.toHex(num) << endl;
}
