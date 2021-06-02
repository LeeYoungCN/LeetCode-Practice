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

void WriteBoolVector(const vector<bool>& array, const string delemiter)
{
    vector<bool>::const_iterator it = array.begin();
    if (it == array.end()) {
        return;
    }

    cout << '[' << (*(it++)? "true": "false");
    while (it != array.end()) {
        cout << delemiter << (*(it++)? "true": "false");
    }
    cout << ']' << endl;
}