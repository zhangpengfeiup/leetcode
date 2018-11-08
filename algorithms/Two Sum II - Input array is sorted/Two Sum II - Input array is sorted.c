#include <stdio.h>
#include <stdlib.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    int *arr;
    arr = (int *)malloc(2* (sizeof(int)));
    int low,high;
    low = 0;
    high = numbersSize-1;

    while (low <= high-1) {
        if (numbers[low] + numbers[high] == target) {
            arr[0] = low+1;
            arr[1] = high+1;
            *returnSize = 2;   // you need assign the *returnSize,otherwise the array will not know the size
            low++;
        }else if (numbers[low]+numbers[high] > target) {
            high--;
        } else {
            low++;
        }
    }

    return arr;
}

int main()
{
    int num[] = {2,7,11,15};
    int target;
    printf("输入您要找的目标值\n");
    scanf("%d",&target);
    int size = 2;
    int *ret;
    int *p = &size;

    ret = twoSum(num,4,target,p);
    int i;
    for (i=0;i<2;i++) {
        printf("%d ",ret[i]);
    }
    return 0;
}
