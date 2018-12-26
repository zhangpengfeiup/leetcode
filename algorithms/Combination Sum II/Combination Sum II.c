#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int compare(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int *candidates,int candidatesSize,int start,int target,int **result,int len,bool *used,int *columnSizes,int *returnSize,int *buf)
{
    int i;
    if (target == 0)
    {
        result[*returnSize] = malloc(len * sizeof(int));
        memcpy(result[*returnSize],buf,len*sizeof(int));
        columnSizes[*returnSize] = len;
        (*returnSize)++;
    }
    else if (target > 0)
    {
        for (i = start; i < candidatesSize; i++)
        {
            if (!used[i])
            {
                if (i > 0 && !used[i-1] && candidates[i-1] == candidates[i])
                {
                    continue;
                }
                used[i] = true;
                buf[len] = candidates[i];
                dfs(candidates,candidatesSize,i+1,target-candidates[i],result,len+1,used,columnSizes,returnSize,buf);
                used[i] = false;
            }

        }
    }
}



int** combinationSum2(int* candidates,int candidatesSize,int target,int** columnSizes,int* returnSize)
{
    qsort(candidates,candidatesSize,sizeof(int),compare);
    int capacity = 100;

    int **result = malloc(capacity * sizeof(int *));
    int *buf = malloc(candidatesSize * sizeof(int));

    *columnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;
    bool *used = malloc(candidatesSize);
    memset(used,false,candidatesSize);
    dfs(candidates,candidatesSize,0,target,result,0,used,*columnSizes,returnSize,buf);
    return result;
}

int main()
{
    int *arr = malloc(7 * sizeof(int));
    arr[0] = 10;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 7;
    arr[4] = 6;
    arr[5] = 1;
    arr[6] = 5;
    int target = 8;
    int *size;
    int returnSize;
    int **list;
    int i,j;

    list = combinationSum2(arr,7,target,&size,&returnSize);
    for (i = 0; i < returnSize; i++)
    {
        for (j = 0; j< size[i]; j++)
        {
            printf("%d ",list[i][j]);
        }
        printf("\n");
    }
    return 0;
}
