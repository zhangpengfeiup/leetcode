#include <stdio.h>
#include <stdlib.h>

/*
	in this propblem,some case fail to pass,
	because in code, I use else if, so some case fail to pass,
	If you are intereseted in it,you can try it.
*/

int maxSubArray(int* nums, int numsSize) {
    int maxSum=nums[0],sum=0,i;
    for (i=0;i<numsSize;i++) {
        sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
        }if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {4,-1,2,1};
    int sum;
    sum = maxSubArray(&arr,4);
    printf("this max sum is %d \n",sum);
    return 0;
}
