/*
 * LeetCode算法练习
 * Description  : 公共函数
 * Author       : 李阳
 * Created      : 2021-03-15
 */
#include <iostream>
#include <vector>
#include <string>

#include "public_function.h"

using namespace std;

int ReadInt(void)
{
    int ret;
    cin >> ret;
    return ret;
}

string ReadLine()
{
    string line;
    getline(cin, line);
    return line;
}

void PrintBoolVector(const vector<bool>& array, const string delemiter)
{
    vector<bool>::const_iterator it = array.begin();
    if (it == array.end()) {
        return;
    }

    cout << '[';
    PrintBool(*it);
    while (it != array.end()) {
        cout << delemiter;
        PrintBool(*it);
    }
    cout << ']' << endl;
}

void PrintBool(bool input)
{
    cout << (input? "true": "false");
}
