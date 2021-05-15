/*
 * LeetCode算法练习
 * Description  : LeetCode题库10题，https://leetcode-cn.com/problems/regular-expression-matching/
 * Author       : 李阳
 * Created      : 2021-04-01
 */
#include "lc0010_rugular_expression_matching.h"

bool RegularExpressionMatch::isMatch(string s, string p) {


    return false;
}

Node::Node(char key) {
    this->key = key;

}

bool Node::push(char x) {

    if(key == '.' || (key != '.' && key == x)){
        strIndex.push_back(x);
        return true;
    }
    return false;
}

void Node::setNum(int number) {
    this->num = number;

    if(key != '.' && num == 0)
        weight = 0;

    if(key == '.' && num == 0)
        weight = 1;

    if(key != '.' && num == 1)
        weight = 2;

    if(key == '.' && num == 1)
        weight = 3;
}
