#include <stdio.h>
#include <stdlib.h>

/*

Learn from https://github.com/begeekmyfriend/leetcode/blob/master/015_three_sum/three_sum.c

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

int compare(const void *a,const void *b) {
    return *(int *)a -  *(int *)b;
}


void twoSum(int *nums,int low,int high,int target,int **results,int * count) {
    while(low < high) {
        int diff;
        //next we will in nums array to find the diff
        diff = target-nums[low];
        if (diff > nums[high]) {
            // nums[low] == nums[low-1] to skip the same number
            while(++low < high && nums[low] == nums[low-1]) {

            }
        } else if (diff < nums[high]){
            // nums[high] == nums[high+1] to skip the same number
            while(--high > low && nums[high] == nums [high+1]) {

            }
        }else {
            results[*count] = malloc(3 *sizeof(int));
            results[*count][0] = -target;
            results[*count][1] = nums[low];
            results[*count][2] = nums[high];
            (*count)++;
            while(++low <high && nums[low] == nums[low-1]) {

            }
            while (--high > low && nums[high] == nums[high+1]) {

            }
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }
    //对数组进行排序
    qsort(nums,numsSize,sizeof(int),compare);
    *returnSize = 0;
    int i,capacity = 50000;
    //为二维数组开辟空间
    int **results = malloc(capacity * sizeof(int *));
    for(i=0;i<numsSize;i++) {
        if (i==0 || (i> 0 && nums[i] != nums[i-1])) {
            twoSum(nums,i+1,numsSize-1,-nums[i],results,returnSize);
        }
    }
    return results;
}

/*
    one Question:
    How do I get the returned  two-dimensional array

*/

int main()
{
    int nums[] = {1,-1,-1,0};
    int i,length,count;
    length = sizeof(nums)/sizeof(nums[0]);
    int **thriplets = threeSum(nums,length,&count);
    for(i=0;i<count;i++) {
        printf("%d %d %d \n",thriplets[i][0],thriplets[i][1],thriplets[i][2]);
    }
    return 0;
}
