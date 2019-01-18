#include <stdio.h>
#include <stdlib.h>

int comp(const void*a,const void*b)
{
    return *(int *)a - * (int *)b;
}

// 这道题主要考察，如何对结果进行出重处理，需要考虑清楚边界条件这些限制条件，同时需要自己多想一些case进行测试
// 于项目来说，合理和正确的使用单元测试是不是更好一点

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{

    if (numsSize < 4 || nums == NULL)
    {
        return NULL;
    }

    qsort(nums,numsSize,sizeof(int),comp);
    int i,j;
    int sum;
    int **ret = NULL;
    *returnSize = 0;

    for (i = 0; i < numsSize-3; i++)
    {
        //去重
        if (i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }

        for (j = i+1; j < numsSize - 2; j++)
        {
            // j > i +1 not j > 0, you can think the case of 0 0 0 0.  j> i + 1 equal j > 0 && j !+ i +1
            //去重
            if (j > 0 && nums[j] == nums[j-1] && j != i+1)
            {

                continue;
            }

            // 减少循环次数  相当于减枝的效果
            if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target)
                break;

             // 减少循环次数  相当于减枝的效果
            if(nums[i]+nums[j]+nums[numsSize-2]+nums[numsSize-1]<target)
                continue;


            int start = j + 1;
            int end = numsSize - 1;

            while (start < end)
            {

                sum = nums[i] + nums[j] + nums[start] + nums[end];

                if (sum == target)
                {

                    (*returnSize)++;
                    ret = (int **)realloc(ret,sizeof(int *) * (*returnSize));
                    int key = (*returnSize) - 1;
                    ret[key] = malloc((*returnSize) * sizeof(int));
                    ret[key][0] = nums[i];
                    ret[key][1] = nums[j];
                    ret[key][2] = nums[start];
                    ret[key][3] = nums[end];

                    // 去重效果
                    while (start < end && nums[start] == nums[start+1])
                    {
                        start++;
                    }

                    while (start < end && nums[end] == nums[end-1])
                    {
                        end--;
                    }

                    start++;
                    end--;
                }
                else if (sum > target)
                {

                    end--;
                }
                else
                {
                    start++;
                }
            }
        }
    }
    return ret;
}

int main()
{
    int **ret,*arr,i,j,size,target,len;
    puts("请输入你要输入元素的个数");
    scanf("%d",&len);
    arr = malloc(len * sizeof(int));
    puts("请输入每个元素的值");
    for (i = 0; i < len; i++)
    {
        scanf("%d",&arr[i]);
    }
    puts("请输入目标和的值");
    scanf("%d",&target);
    ret = fourSum(arr,len,target,&size);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ",ret[i][j]);
        }
        printf("\n");
    }

    printf("Hello world!\n");
    return 0;
}
