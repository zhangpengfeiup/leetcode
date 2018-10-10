#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 /**
  *  the second array of binary serarch
  **/
bool searchMatrix(int** matrix,int matrixRowSize,int matrixColSize,int target) {
    int col,low,high,mid;
    for (col=0;col<matrixRowSize;col++) {
        if (target <= matrix[col][matrixColSize-1]) {
                low = 0;
                high = matrixColSize-1;
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (matrix[col][mid] == target) {
                        return true;
                    }else if (matrix[col][mid] > target) {
                        high = mid -1;
                    }else {
                        low = mid+1;
                    }
                }
            return false;
        }
    }
    return false;
}


int main()
{
    int n1,n2,target;
    bool ret;
    int **array,i,j;
    puts("输入一维长度:");
    scanf("%d",&n1);
    puts("输入二维长度:");
    scanf("%d",&n2);
    array = (int**)malloc(n1*sizeof(int*)); //第一维
    for (i=0;i<n1;i++) {
        array[i] = (int*)malloc(n2*sizeof(int)); //第二维
        for (j=0;j<n2;j++) {
            int q;
            scanf("%d",&q);
            array[i][j] = q;
        }
    }
    for (i=0;i<n1;i++) {
        for (j=0;j<n2;j++) {
            printf("arr[%d][%d] = %d \n",i,j,array[i][j]);
        }
    }
     puts("输入target");
    scanf("%d",&target);
    ret = searchMatrix(array,n1,n2,target);
    if (ret) {
        printf("find it\n");
    }else {
        printf("not find it");
    }
    return 0;
}
