#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// refer to http://www.cnblogs.com/grandyang/p/4325840.html

int search(int *nums,int numsSize,int target) {
    int left,right,mid;
    left =0;right=numsSize-1;
    while(left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return true;
        }else if (nums[mid] < nums[right]) {   //右半部分递增
            if (nums[mid] < target && nums[right] >= target) {
                left = mid +1;
            }else {
                right = mid -1;
            }
        }else if (nums[mid] > nums[right]){
            if (nums[left] <= target && nums[mid] > target) {
                right = mid - 1;
            }else {
                left = mid+1;
            }
        }else {
            right--;
        }
    }
    return false;
}

int main()
{
    int num,i,value,target,ret;
    printf("输入数组的长度");
    scanf("%d",&num);
    int *array = malloc(num*sizeof(int));
    //输入数组每个下标的值
    for (i=0;i<num;i++) {
        scanf("%d",&value);
        array[i] = value;
    }
    printf("数组中的所有的值为\n");
    for(i=0;i<num;i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
    printf("请输入您要查找的值\n");
    scanf("%d",&target);
    ret = search(array,num,target);
    if (ret) {
        printf("你查找的数存在\n");
    }else {
        printf("你查找的数不存在\n");
    }



    return 0;
}
