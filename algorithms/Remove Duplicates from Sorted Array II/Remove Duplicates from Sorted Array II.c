#include <stdio.h>
#include <stdlib.h>

/*
 *  traverse the array,and an nonius forward,and the count record the repetition num.
 */

int removeDuplicates(int *nums,int numsSize) {
    if (numsSize <=0) {
        return 0;
    }
   int j,count,cur;
   count =0;
   cur = 1;
   for(j=1;j<numsSize;j++) {
        if (nums[j] == nums[j-1]) {
            count++;
            if (count < 2) {
                nums[cur] = nums[j];
                cur++;
            }
        } else {
            count = 0;
            nums[cur] = nums[j];
            cur++;
        }
   }
   return cur;
}

/**
 * Attention: nums[j] compare to nums[index-2],because index is the last array we will return
 *  so we need compare the nums[index-2] to the nums[j]
 */
int removeDuplicates2(int *nums,int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    if (numsSize < 3) {
        return numsSize;
    }
    int j;
    int index = 2;
    for (j=2;j<numsSize;j++) {
        if(nums[j] != nums[index-2]) {
            nums[index++] = nums[j];
        }
    }
    return index;
}

int main() {
    int num;
    scanf("%d",&num);
    int *array = malloc(num*sizeof(int));
    int i,value,len;
    for (i=0;i<num;i++) {
        scanf("%d",&value);
        array[i] = value;
    }
    int len2;
    len = removeDuplicates(array,num);
    len2 = removeDuplicates2(array,num);
    printf("%d\n",len);
    printf("%d\n",len2);
    return 0;
}
