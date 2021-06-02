/*
 * LeetCode算法练习
 * Description  : LeetCode题库9题，https://leetcode-cn.com/problems/palindrome-number/
 * Author       : 李阳
 * Created      : 2021-03-31
 */
/*
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false
 */

#include "lc0009_palindrome_number.h"

bool method1::PalindromeNumber::isPalindrome(int x) {
    if (x < 0)             return false;
    if (x%10 == 0 && x!=0) return false;

    int newInt = 0;
    while (x > newInt) {
        newInt = newInt * 10 + x % 10;
        x /= 10;
    }

    return x == newInt || x == newInt / 10;
}

bool method2::PalindromeNumber::isPalindrome(int x) {
    if (x < 0)             return false;
    if (x >= 0 && x < 10)  return true;

    int n = (int)log10(x) + 1;
    int half = n/ 2;

    int left   = x / (int)pow(10, n - half);
    int right  = x % (int)pow(10, half);
    int newInt = 0;

    while (left) {
        int endNum = left % 10;
        newInt = newInt * 10 + endNum;
        left /= 10;
    }

    return right == newInt;
}

bool method3::PalindromeNumber::isPalindrome(int x) {
    if (x < 0) return false;
    if(x>-1 && x<10) return true;

    int n = (int)log10(x) + 1;

    while (n>1) {
        int left  = x/(int)pow(10, n-1);
        int right = x%10;

        if(left != right)
            return false;
        x = x - left * (int)pow(10, n-1);
        x = x/10;

        n-=2;
    }

    return true;
}
