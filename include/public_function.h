/*
 * LeetCode算法练习
 * Description  : 公共函数
 * Author       : 李阳
 * Created      : 2021-03-15
 */

#ifndef PUBLIC_FUNCTION_H
#define PUBLIC_FUNCTION_H

#include <vector>
#include <string>
using namespace std;
int ReadInt(void);
std::string ReadLine();

template<typename T>
std::vector<T> ReadVector(const int size)
{
    vector<T> ret(size);
    for (int i = 0; i < size; i++) {
        cin >> ret[i];
    }
    return ret;
}

template<typename T>
void WriteVector(const std::vector<T> array, const string delemiter = " ")
{
    auto it = array.begin();
    if (it == array.end()) {
        return;
    }
    cout << *(it++);
    while(it != array.end()) {
        cout << delemiter << *(it++);
    }
}

#endif // PUBLIC_FUNCTION_H