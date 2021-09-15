/*
 * LeetCode算法练习
 * Description  : LeetCode题库4题, https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * Author       : 李阳
 * Created      : 2021-09-14
 */
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include "public_function.h"
#include "lc0004_median_of_two_sorted_arrays.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double m = 0;
        double n = 0;
        int total = nums1.size() + nums2.size();
        if (total % 2) {
            m = GetKthValue(total/2 + 1, nums1, nums2);
            n = m;
        } else {
            m = GetKthValue(total/2,     nums1, nums2);
            cout << "m = " << m << endl;
            n = GetKthValue(total/2 + 1, nums1, nums2);
            cout << "n = " << n << endl;
        }
        
        return (m + n)/2;
    }
private:
    int GetKthValue(int K, vector<int>& nums1, vector<int>& nums2)
    {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        int start1 = 0;
        int start2 = 0;
        
        while(true) {
            if (start1 == N1) {
                return nums2[start2 + K - 1];
            } else if (start2 == N2) {
                return nums1[start1 + K -1];
            } else if (K==1) {
                return min(nums1[start1], nums2[start2]);
            }

            int halfK = K / 2;
            int newIndex1 = min(start1 + halfK - 1, N1 - 1);
            int newIndex2 = min(start2 + halfK - 1, N2 - 1);
            int value1 = nums1[newIndex1];
            int value2 = nums2[newIndex2];
            int delta = 0;
            if (value1 <= value2) {
                delta  = newIndex1 - start1 + 1;
                start1 = newIndex1 + 1;
            } else {
                delta  = newIndex2 - start2 + 1;
                start2 = newIndex2 + 1;
            }
            K -= delta;
        }
        return 0;
    }
};

void LC0004Test()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2,4};
    Solution solu;
    cout << solu.findMedianSortedArrays(nums1, nums2) << endl;
}
