/*
 * LeetCode算法练习
 * Description  : LeetCode题库726题，https://leetcode-cn.com/problems/number-of-atoms/
 * Author       : 李阳
 * Created      : 2021-07-05
 */
#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

#include "public_function.h"
#include "lc0726_number_of_atoms.h"

using namespace std;

enum STATE{
    NUM,
    ABC,
    abc,
    START,
    END,
};

class Solution {
public:
    string countOfAtoms(string formula) {
        string ret;
        auto begin = formula.begin();
        auto map = CreateMap(begin, formula.end());
        for (pair<string, int> p:map) {
            ret += p.first + (p.second > 1 ? to_string(p.second) : "");
        }
        return ret;
    }

private:
    map<string, int> CreateMap(string::iterator& it, string::iterator end)
    {
        map<string, int> ret;
        while(it != end) {
            string atom = GetAtom(it, end);
            if (!atom.empty()) {
                int num = GetNum(it, end);
                ret[atom] += num;
            } else if (Judge(*(it++)) == START) {
                auto tmp = CreateMap(it, end);
                for (pair<string, int> p: tmp) {
                    ret[p.first] += p.second;
                }
            } else {
                break;
            }
        }

        int N = GetNum(it, end);
        if (N > 1) {
            for (pair<string, int> p:ret) {
                ret[p.first] *= N;
            }
        }
        return ret;
    }

    string GetAtom(string::iterator& it, string::iterator end)
    {
        string atom;
        if (it !=end && Judge(*it) == ABC) {
            atom += *(it++);
            while (it !=end && Judge(*it) == abc) {
                atom += *(it++);
            }
        }
        return atom;
    }

    int GetNum(string::iterator& it, string::iterator end)
    {
        string numStr;
        int num = 0;
        while (it !=end && Judge(*it) == NUM) {
            numStr += *(it++);
        }
        for (char c: numStr) {
            num = 10 * num + c - '0';
        }

        return max(1, num);
    }

    STATE Judge(char c)
    {
        if (c >= 'A' && c <= 'Z') {
            return ABC;
        }
        if (c >= 'a' && c <= 'z') {
            return abc;
        }
        if (c >= '0' && c <= '9') {
            return NUM;
        }
        if (c == '(') {
            return START;
        }

        return END;
    }
};

void LC0726Test()
{
    string formula = "H2O";
    Solution solu;
    cout << solu.countOfAtoms(formula) << endl;
}