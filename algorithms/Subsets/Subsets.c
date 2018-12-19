#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * The First method is use loop add the element.
 * Refer to the https://leetcode.com/problems/subsets/discuss/193014/Simple-C-solution
 * It is interesting is the temp count colsize result in change.
 * If you do not understand it.You can draw the fours change in the paper.
 * temp  count colsize result
 * Beside you need careful that you need init the colSize array.so in the c Language,we use calloc assign the space.
 *
 * The second method is dfs   you can refer to the https://github.com/begeekmyfriend/leetcode/blob/master/078_subsets/subsets.c
 *             []

            1                []

       1,2     1          2       []

 1,2,3  1,2  1,3  1   2,3   2    3   []
 */
int** subsets(int *nums,int numsSize,int** columnSizes,int* returnSize)
{

    int max,temp,count;
    max = pow(2,numsSize);
    *returnSize = max;
    int **result;
    result = malloc(max * sizeof(int*));
    int *colSize;
    colSize = calloc(*returnSize, sizeof(int));
    int i;
    for (i = 0; i < max; i++)
    {
        result[i] = malloc(numsSize * sizeof(int));
    }

    i = 0;
    while(i < max)
    {

        if (i == 0)
        {
            colSize[i] = 0;
            result[i] = NULL;
        }
        else if(i == 1)
        {
            colSize[i] = 1;
            result[i] = malloc(colSize[i] * sizeof(int));
            result[i][0] = nums[i-1];
        }
        else
        {
            temp = i;
            count = 0;
            while(temp != 0)
            {
                if (temp % 2 == 1)
                {
                    colSize[i]++;
                    result[i] = realloc(result[i],colSize[i] * sizeof(int));
                    result[i][colSize[i]-1] = nums[count];
                }
                count++;
                temp/=2;

            }
        }

        i++;
    }
    *columnSizes = colSize;

    return result;
}

/*
void dfs(int *nums,int size,int start,int *buf,int len,int **result,int *sizes,int *count)
{
    result[*count] = malloc(len * sizeof(int));
    memcpy(result[*count],buf,len*sizeof(int));
    sizes[*count] = len;
    (*count)++;
    int i;
    for (i = start;i<size;i++) {
        buf[len] = nums[i];
        dfs(nums,size,i+1,buf,len+1,result,sizes,count);
    }
}

int** subsets(int *nums,int numsSize,int** columnSizes,int* returnSize) {
    int capacity = 5000;
    int **result = malloc(capacity * sizeof(int *));
    // buf the max is numsSize,when it has all
    int *buf = malloc(numsSize * sizeof(int));
    *columnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    dfs(nums,numsSize,0,buf,0,result,*columnSizes,returnSize);
    return result;
}
*/


int main()
{
    int num = 3;
    int *arr = malloc(3*sizeof(int));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    int *sizes;
    int count;
    int **list;
    list = subsets(arr,num,&sizes,&count);

    int i,j;
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            printf("%d ",list[i][j]);
        }
        printf("\n");
    }
    return 0;
}
