/*
 * LeetCode算法练习
 * Description  : 公共函数
 * Author       : 李阳
 * Created      : 2021-03-15
 */

#ifndef PUBLIC_FUNCTION_H
#define PUBLIC_FUNCTION_H
#include <iostream>
#include <vector>
#include <string>

int ReadInt(void);
std::string ReadLine(void);
void PrintBool(bool input);
void WriteBoolVector(const std::vector<bool>& array, std::string delemiter = ", ");

template<typename T>
std::vector<T> ReadVector(const int size)
{
    std::vector<T> ret(size);
    for (int i = 0; i < size; i++) {
        std::cin >> ret[i];
    }
    return ret;
}

template<typename T>
void WriteVector(const std::vector<T> array, const std::string delemiter = ", ")
{
    auto it = array.begin();
    if (it == array.end()) {
        return;
    }
    std::cout << '[' << *(it++);
    while(it != array.end()) {
        std::cout << delemiter << *(it++);
    }
    std::cout << ']' << std::endl;
}

#endif // PUBLIC_FUNCTION_H
