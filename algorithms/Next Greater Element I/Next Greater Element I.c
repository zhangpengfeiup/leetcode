#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data[1000];
    int top;
}SqStack;

bool Init(SqStack *S) {
    S->top = -1;
    return true;
}

bool Push(SqStack *S,int e) {
    S->top++;
    S->data[S->top] = e;
    return true;
}

bool Pop(SqStack *S) {
    if (S->top == -1) {
        return false;
    }
    S->top--;
    return true;
}

bool EmptyStack(SqStack S) {
    if (S.top == -1) {
        return true;
    }
    return false;
}

int GetTop(SqStack S) {
   if (S.top == -1) {
      return 0;
   }
   return S.data[S.top];
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int i,j,k;
    int *ret;
    ret = (int *)malloc(findNumsSize * sizeof(int));
    for (i=0;i<findNumsSize;i++) {

        for (j=0;j<numsSize;j++) {
            if (nums[j] == findNums[i]) {
                ret[i] = -1;

                for(k=j+1;k<numsSize;k++) {
                    if (nums[k] > nums[j]) {
                        ret[i] = nums[k];
                        break;
                    }
                }
              break;
            }
        }
    }
    *returnSize = findNumsSize;
    return ret;
}

//use the hash to reduce the time complexity
int* nextGreaterElement2(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int i,j;
    int *ret;
    ret = (int *)malloc(findNumsSize * sizeof(int));

     int max = 0;
     // in the here I don't know why we need calculate the max of nums.If not it will error: free(): invalid next size (fast): 0x0000000002110440 ***
     // if you know it.You can tell me why we need do it.It is very kind of you.
     for(int i = 0; i < numsSize; i++) {
            if(max < nums[i]) {
                max = nums[i];
            }
     }

     int *numsHash = (int *)malloc((max+1) * sizeof(int));
    for (j=0;j<numsSize;j++) {
        numsHash[nums[j]] = j;
    }
    for (i=0;i<findNumsSize;i++) {
         ret[i] = -1;
         int start = numsHash[findNums[i]];
         for (j=start+1;j<numsSize;j++) {
              if (nums[j] > findNums[i]) {
                 ret[i] = nums[j];
                 break;
              }
         }
    }

    free(numsHash);

    *returnSize = findNumsSize;
    return ret;
}

//we will use the stack to find where the next generate. But the time complexity do not decrease.
int* nextGreaterElement3(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {

    *returnSize = findNumsSize;
    int *ret = (int *)malloc(*returnSize * sizeof(int));
    int max = 0;
     int i,j;
     for (j=0;j<numsSize;j++) {
        if (nums[j] > max) {
            max = nums[j];
        }
     }
    int *numsHash = (int *)malloc((max+1) * sizeof(int));

    SqStack S;
    Init(&S);
    for (j=0;j<numsSize;j++) {
        numsHash[nums[j]] = -1;
        while(!EmptyStack(S) && GetTop(S) < nums[j]) {
            numsHash[GetTop(S)] = nums[j];
            Pop(&S);
        }
        Push(&S,nums[j]);
    }

    for (j=1;j<numsSize+1;j++) {
        printf("%d ",numsHash[j]);
    }
    printf("\n");

    for (i=0;i<findNumsSize;i++) {
        ret[i] = numsHash[findNums[i]] == -1 ? -1 : numsHash[findNums[i]];
    }

    return ret;
}

int main()
{
    int m,n,i;
    m = 3;
    n = 4;
    int *findNums = (int *)malloc(m*sizeof(int));
    findNums[0] = 4;
    findNums[1] = 1;
    findNums[2] = 2;

    int *nums = (int *)malloc(n*sizeof(int));
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 4;
    nums[3] = 2;

    int *ret;
    ret = (int *)malloc(m * sizeof(int));
	// three method you can try it nextGreaterElement1 nextGreaterElement2 nextGreaterElement3
    ret =  nextGreaterElement3(findNums,m,nums,n,ret);
    for (i=0;i<m;i++) {
        printf("%d ",ret[i]);
    }

    printf("Hello world!\n");
    return 0;
}
