/**
 * @file main.c
 * @author timwilliam (findtimwilliam@gmail.com)
 * @brief LeetCode: 896. Monotonic Array
 * @version 1.0
 * @date 2024-02-23
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Check if array is monotonic increase or decrease
 * 
 * @remark Time complexity = O(n)
 * 
 * @param nums Input array
 * @param numsSize Input array size
 * @return true If monotonic increase or decrease
 * @return false If not monotonic increase or decrease
 */
bool isMonotonic(int* nums, int numsSize) {
    int i = 1;
    bool increaseFlag = false;
    bool decreaseFlag = false;

    // Find the index where the number starts to increase or decrease
    while(increaseFlag == false && decreaseFlag == false && i < numsSize) {
        if(nums[0] > nums[i])
            decreaseFlag = true;
        else if(nums[0] < nums[i])
            increaseFlag = true;
        else
            i++;
    }

    // In case where the array is homogenous, return true
    if(increaseFlag == false && decreaseFlag == false)
        return true;

    // Go through the rest of the array, return false when number is no longer increasing/decreasing
    for(i = i; i < numsSize - 1; i++) {
        if(increaseFlag) {
            if(nums[i] > nums[i+1])
                return false;
        } else if(decreaseFlag) {
            if(nums[i] < nums[i+1])
                return false;
        }
    }

    return true;
}

int main(void){
    // int nums[] = {1, 2, 3, 3};      // 1
    // int nums[] = {6, 5, 4, 4};      // 1
    // int nums[] = {1, 3, 2};      // 0
    int nums[] = {1, 1, 1};     // 0

    printf("%d\n", isMonotonic(nums, sizeof(nums) / sizeof(nums[0])));

    return 0;
}