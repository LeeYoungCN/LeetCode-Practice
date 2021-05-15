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