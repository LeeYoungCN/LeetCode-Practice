/*
 * LeetCode算法练习
 * Description  : LeetCode题库523题, https://leetcode-cn.com/problems/continuous-subarray-sum/description/
 * Author       : 李阳
 * Created      : 2021-05-19
 *
 * [523]连续的子数组和
 *
 *
 * https://leetcode-cn.com/problems/continuous-subarray-sum/description/
 *
 *
 * 给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。
 * 示例 1:
 * 输入: [23,2,4,6,7], k = 6
 * 输出: True
 * 解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
 * 
 * 示例 2:
 * 输入: [23,2,6,4,7], k = 6
 * 输出: True
 * 解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
 * 
 * 说明:
 * 
 * 数组的长度不会超过10,000。
 * 你可以认为所有数字总和在 32 位有符号整数范围内。
 * 
 * 
 */

#ifndef LC0523_CONTINUOUS_SUBARRAY_SUM_H
#define LC0523_CONTINUOUS_SUBARRAY_SUM_H

void LC0523Test(void);

#endif // LC0523_CONTINUOUS_SUBARRAY_SUM_H