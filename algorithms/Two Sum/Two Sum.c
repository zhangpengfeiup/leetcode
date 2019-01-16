#include <stdio.h>
#include <stdlib.h>

//brute force 第一种方法:依次求解
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *ret = malloc(2 * sizeof(int));
    for (i = 0;i < numsSize;i++) {
        for (j = i+1;j < numsSize;j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                break;
            }
        }
    }
    return ret;
}

int comp(const void*a,const void *b) {
    return *(int *)a - *(int *)b;
}


typedef struct {
    int idx;
    int val;
}arr_t;

int cmp(const void* a, const void* b){
    return ((const arr_t*)a)->val - ((const arr_t*)b)->val;
}


/*
 qsort and then use tow pointer to find result
 排序，然后使用两个指针分别指向首尾进行寻找target值
 但是发现题目中给的数组并没有要求进行排序，而仅仅是求两个值得下标，所以我们排序的时候需要记录下来每个值初始的下标，这样排序以后根据值找到元素初始的下标
 但是怎么通过value值找到元素原始的下标呢，那这里需要用到hash去保存值对应的下标，这个时候又有问题了，值重复的话，hash怎么的下标怎么处理？这样处理又不是很好，
 我们想，有没有可能排序value的值，保持数组的索引的下标呢，类似PHP数组操作中asort那样，看了一下这道题的最优解，0ms的代码，牛逼，通过定义结构体，结构体保存了下标和value的值，
 然后对值进行升序排序，然后发现我们就实现了保持索引下标的排序了，6不6,66666666，哈哈哈哈哈哈。
 还有需要注意的是,idx 是结构体中的下标，和我们进行数据循环的下标不一样,循环的代码对应我们下边代码中的start,end;
*/

int* twoSum1(int* nums, int numsSize, int target) {
    //定义结构体数组arr_nums
    arr_t arr_nums[numsSize];
    //初始化arr_nums
    int i;
    for (i = 0;i < numsSize;i++) {
        arr_nums[i].idx = i;
        arr_nums[i].val = nums[i];
    }

    //去掉printf的注释，你就可以类比看看排序前后排序后的区别了
    for(i = 0;i<numsSize;i++) {
        //printf("%d %d\n",arr_nums[i].idx,arr_nums[i].val);
    }

    qsort(arr_nums,numsSize,sizeof(arr_t),cmp);
    for(i = 0;i<numsSize;i++) {
        //printf("%d %d\n",arr_nums[i].idx,arr_nums[i].val);
    }

    int *ret = malloc(2 * sizeof(int));
    int start,end;
    start = 0;
    end = numsSize - 1;

    while (start < end) {
        if (arr_nums[start].val + arr_nums[end].val > target) {
            end--;
        }else if (arr_nums[start].val + arr_nums[end].val < target) {
            start++;
        }else {
            ret[0] = arr_nums[start].idx;
            ret[1] = arr_nums[end].idx;
            break;
        }
    }
    return ret;
}


int main()
{
    int *arr,*ret;
    int i,target,len;
    printf("请输入数组的长度\n");
    scanf("%d",&len);
    arr = (int *)malloc(len * sizeof(int));
    puts("请输入数组元素的值");
    for (i = 0;i < len;i++) {
        scanf("%d",&arr[i]);
    }
    puts("请输入目标的值\n");
    scanf("%d",&target);

    ret = twoSum1(arr,len,target);
    puts("结果下标为");
    for (i = 0;i < 2;i++) {
        printf("%d ",ret[i]);
    }
    return 0;
}
