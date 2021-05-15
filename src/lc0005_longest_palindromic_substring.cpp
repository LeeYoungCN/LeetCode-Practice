/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description  : LeetCode题库5题，https://leetcode-cn.com/problems/longest-palindromic-substring/
 * Author       : 李阳 l0050626
 * Created      : 2021-03-39
 */

#include "lc0005_longest_palindromic_substring.h"

namespace method1{

    string ZigZagConversion::longestPalindrome(string s){
        string subStr;
        size_t length = s.size();
        bool** dp = Pointer<bool>::pMatrix(length, length, false);

        for(size_t l = 1; l <= length; l++){

            for(size_t i = 0; i <= length-l; i++){
                int j = i+l-1;
                if(l == 1){
                    dp[i][j] = true;
                } else
                if(l == 2){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }

                if(dp[i][j] && l > subStr.size()){
                    subStr = s.substr(i, l);
                }
            }
        }
        return subStr;
    }

}

namespace method2{

    string ZigZagConversion::longestPalindrome(string s){
        string subStr;
        int    l_max = 0;
        int    start = 0;
        int    length = s.size();

        for(int i = 0; i < length; i++){
            int l1 = expandAroundCenter(s, i, i);
            int l2 = expandAroundCenter(s, i, i+1);

            int l_tmp = l1>l2? l1: l2;

            if(l_tmp > l_max){
                l_max = l_tmp;
                start = i - (l_max-1)/2;
            }
        }

        subStr = s.substr(start, l_max);
        return subStr;
    }

    int ZigZagConversion::expandAroundCenter(string s, int left, int right){
        while(left >= 0 && right < (int)(s.size()) && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left -1;
    }
}

namespace method3{

    string ZigZagConversion::longestPalindrome(string s){
        int  len_max = 0;
        int  lef_max = 0;

        int  length = 2*s.size()+1;
        int* arm_len = Pointer<int>::pArray(length);

        s = toOddLength(s);

        int right = -1;
        int j = -1;
        for(int i = 0; i < length; i++){
            int arm_cur = 0;
            if(right >= i){
                int i_sym = 2*j - i;
                int arm_min = arm_len[i_sym] < right-i? arm_len[i_sym]: right-i;

                arm_cur = getArmLen(s, i-arm_min, i+arm_min);

            }else{
                arm_cur = getArmLen(s, i, i);
            }

            arm_len[i] = arm_cur;

            if(i + arm_cur > right){
                j = i;
                right = i+arm_cur;
            }

            if(2*arm_cur+1 > len_max){
                len_max = 2*arm_cur+1;
                lef_max = j - arm_cur;
            }
        }

        return subString(s, lef_max, len_max);
    }

    string ZigZagConversion::toOddLength(string s){
        string odd_str;

        for(char c: s){
            odd_str += '#';
            odd_str += c;
        }
        odd_str += '#';

        return odd_str;
    }

    int ZigZagConversion::getArmLen(string s, int left, int right){
        int length = s.size();
        while(left >= 0 && right < length && s[left] == s[right]){
            left--;
            right++;
        }

        return (right - left-2)/2;
    }

    string ZigZagConversion::subString(string s, int left, int length){
        string subStr;

        for(int i = 0; i< length; i++){
            char c = s[left+i];
            if(c == '#'){
                continue;
            }
            subStr += c;
        }
        return subStr;
    }
}