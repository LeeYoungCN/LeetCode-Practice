/*
 * LeetCode算法练习
 * Description  : LeetCode题库7题，https://leetcode-cn.com/problems/reverse-integer/
 * Author       : 李阳
 * Created      : 2021-03-30
 */
#include <iostream>
using namespace std;

#include "lc0007_reverse_integer.h"

/**
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 */

namespace method1{
    int ReverseInteger::reverse(int x) {
        int newInt = 0;

        for(int i=0;x != 0; i++){
            int end = x%10;
            if(i==9){
                if(INT32_MIN/10 > newInt ||  (INT32_MIN/10 < newInt && end < -8)){
                    return 0;
                }

                if(INT32_MAX/10 < newInt || (INT32_MAX/10 > newInt && end > 7))
                    return 0;
            }

            newInt  = 10 * newInt + end;
            x  = x/10;
        }

        return newInt;
    }
}