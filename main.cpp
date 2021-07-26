#include <iostream>
#include <algorithm>
#include <vector>

#include <iterator>

#include "leetcode_head.h"
using namespace std;

class MyIterator:iterator<input_iterator_tag, int> {
    int* p = NULL;
public:
    MyIterator(int* x):p(x) {}
    MyIterator(const MyIterator& mit):p(mit.p) {}
    MyIterator& operator++ ()
    {
        this->p++;
        cout << "operator++" << endl;
        return *this;
    }
    MyIterator operator++ (int) 
    {
        MyIterator tmp(*this);
        operator++();
        cout << "operator++ int" << endl;
        return *this;
    }
    int& operator*()
    {
        return *p;
    }
    bool operator== (MyIterator other)
    {
        return p==other.p;
    }
    bool operator!= (MyIterator other)
    {
        return p!=other.p;
    }
};

int main(int argc, char *argv[]) 
{
    int list[] = {0,1,2,3,4,5,6};
    MyIterator begin(list);
    MyIterator end(list+7);
    for (MyIterator it = begin; it != end; it++) {
        cout << *it << endl;
    }
    

    return 0;
}

