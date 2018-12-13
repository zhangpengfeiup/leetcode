#include <stdio.h>
#include <stdlib.h>

// the brute force of mine

/*
    At the first,I use the judge the ret[i] is -1 to judge the for loop go to the tail.
    But in the test case,find in the array num value may be -1.
    So we can not use this judge.
*/
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int i,j;
    *returnSize = numsSize;
    int *ret = (int *)malloc(numsSize * sizeof(int));
    for (i=0;i<numsSize;i++) {

        ret[i] = -1;

        for (j = i+1;j < numsSize; j++) {
            if (i == j) {
                continue;
            }

            if (nums[j] > nums[i]) {
                ret[i] = nums[j];
                break;
            }
        }

        if (j == numsSize) {
            for (j=0;j<i;j++) {
               if (i == j) {
                       continue;
                   }

                if (nums[j] > nums[i]) {
                    ret[i] = nums[j];
                    break;
                }
            }
        }


    }
    return ret;
}

// see the answer the for loop we can change while loop go to it.
// the problem also can use the stack in it. I think the stack is very funny.And in the problem,it it not obvious.
int* nextGreaterElements2(int* nums, int numsSize, int* returnSize) {
    int i,j;
    *returnSize = numsSize;
    int *ret = (int *)malloc(numsSize * sizeof(int));
    for (i=0;i<numsSize;i++) {

        ret[i] = -1;

        j = i +1;
        while(j!=i) {
            if (j >= numsSize) {
                j = 0;
            } else {
                if (nums[j] > nums[i]) {
                    ret[i] = nums[j];
                    break;
                }
                j++;
            }
        }


    }
    return ret;
}



int main()
{
    int i,n;
    n = 8;
    int *nums = (int *)malloc(n*sizeof(int));
    nums[0] = 1;
    nums[1] = 8;
    nums[2] = -1;
    nums[3] = -100;
    nums[4] = -1;
    nums[5] = 222;
    nums[6] = 1111111;
    nums[7] = -111111;
    int *ret;
    ret = (int *)malloc(n * sizeof(int));
    ret = nextGreaterElements2(nums,n,ret);
    for (i = 0;i < n; i++) {
        printf("%d ",ret[i]);
    }
    return 0;
}
