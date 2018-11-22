#include<stdio.h>
#include <stdlib.h>



void rotate(int *nums,int numsSize,int k) {
    k = k % numsSize;
    int i;
    for (i=0;i<k;i++) {
        int j,tmp;
        tmp = nums[numsSize-1];
        for (j=numsSize-1;j>=1;j--) {
            nums[j] = nums[j-1];
        }
        nums[0] = tmp;
    }
}

int main() {
    int *arr;
    int n,i,k;
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("input the k num \n");
    scanf("%d",&k);
    rotate(arr,n,k);
    for (i=0;i<n;i++) {
        printf("%d",arr[i]);
    }
}
