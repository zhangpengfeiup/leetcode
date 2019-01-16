#include <stdio.h>
#include <stdlib.h>

int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

// refer from https://leetcode.com/problems/3sum/discuss/142616/clean-C-solution
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    // sort
    if (numsSize < 3 || nums == NULL)
    {
        return NULL;
    }

    qsort(nums,numsSize,sizeof(int),comp);
    int i;
    *returnSize = 0;
    // you need assign the ret is NUll,otherwise realloc the ret will be wrong
    int **ret = NULL;


    for (i = 0; i < numsSize; i++)
    {
        int start = i + 1;
        int end = numsSize - 1;
        int sum;

        //handles duplicates for i position
        if (i > 0 && nums[i] == nums[i-1])
        {
            continue;
        }


        while (start < end)
        {
            sum = nums[i] + nums[start] + nums[end];

            if (sum == 0)
            {

                (*returnSize)++;
                ret = (int **)realloc(ret,sizeof(int *) * (*returnSize));
                int key = (*returnSize) - 1;

                ret[key] = malloc(3 * sizeof(int));
                ret[key][0] = nums[i];
                ret[key][1] = nums[start];
                ret[key][2] = nums[end];

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
            else if (sum > 0)
            {
                end--;
            }
            else
            {
                start++;
            }
        }


    }
    return ret;
}

int main()
{
    int **ret,*arr,size,i,j,len;
    puts("请输入你要输入元素的个数");
    scanf("%d",&len);
    arr = malloc(len * sizeof(int));
    puts("请输入每个元素的值");
    for (i = 0; i < len; i++)
    {
        scanf("%d",&arr[i]);
    }

    ret = threeSum(arr,len,&size);
    printf("size is %d\n",size);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ",ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
