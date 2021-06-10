/*
 * LeetCode算法练习
 * Description  : LeetCode题库6题，https://leetcode-cn.com/problems/zigzag-conversion/
 * Author       : 李阳
 * Created      : 2021-03-30
 */
#include "lc0006_zig_zag_conversion.h"

string method1::ZigZagConversion::convert(string s, int numRows) {
    int    length  = s.size();
    int    chrNums = numRows + max(0, numRows-2);
    int    numCols = (length+chrNums-1) / chrNums;
    string newStr;

    for (int r = 0; r < numRows; r++) {
        int delta  = numRows - 1 - r;                   // 要找的值与中心点之间的位置关系

        for(int c = 0; c < numCols; c++){
            int center = numRows - 1 + c*chrNums;       // 第n行的点为中心点
            int left   = center - delta;
            int right  = center + delta;

            if(left<length)
                newStr += s[left];

            if(r == 0 || r == numRows-1)
                continue;

            if (right < length)
                newStr += s[right];

        }
    }
    return newStr;
}

string method2::ZigZagConversion::convert(string s, int numRows) {
    int    length  = s.size();

    if(numRows == 1)    return s;
    int chrNums = 2*numRows - 2;

    string newStr;
    // left  =     k*chrNums+r
    // right = (k+1)*chrNums-r
    for(int r = 0; r<numRows; r++){
        for(int j = 0; j+r < length; j += chrNums){
            newStr += s[j+r];

            if(r != 0 && r != numRows-1 && j+chrNums-r < length)
                newStr += s[j+chrNums-r];
        }
    }

    return newStr;
}


string method3::ZigZagConversion::convert(string s, int numRows) {
    int    length = s.size();
    int    minRow = min(length, numRows);
    string strRow[minRow];
    string newStr;

    for(int i = 0, j = 0, dir = 0; i<length; i++){
        if(j == 0 && minRow > 1){
            dir =  1;
        }
        if(j == numRows-1&& minRow > 1) {
            dir = -1;
        }

        strRow[j] += s[i];
        j += dir;
    }

    for(int i = 0; i<minRow; i++){
        cout << strRow[i] << endl;
        newStr += strRow[i];
    }

    return newStr;
}
