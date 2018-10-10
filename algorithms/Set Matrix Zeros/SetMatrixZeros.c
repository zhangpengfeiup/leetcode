#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
 *  I don't know what is int** matrix,so i create the array dymaic from baike.
 *  sometimes we think it easy,but the variate i,j need we focus
 *  becaus in the array it will overflow if we use it wrong
 *  so the row and column we need foucu on the second array.
 **/

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
      int i,j;

    bool rowFlag = false,colFlag = false;
    //使用rowFlag 和colFlag 变量标记第一行和第一列是否有0，然后第一行，第一列标记其余行和列是否有0
    for (j=0;j<matrixColSize;j++) {
        if (matrix[0][j] == 0) {
            rowFlag = true;
            break;
        }
    }
    for (i=0;i<matrixRowSize;i++) {
        if (matrix[i][0] == 0) {
            colFlag = true;
            break;
        }
    }
    for (i=1;i<matrixRowSize;i++) {
        for (j=1;j<matrixColSize;j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (i=1;i<matrixRowSize;i++) {
        for (j=1;j<matrixColSize;j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (rowFlag) {
        for (i=0;i<matrixColSize;i++) {
            matrix[0][i] = 0;
        }
    }
    if (colFlag) {
        for (j=0;j<matrixRowSize;j++) {
            matrix[j][0] = 0;
        }
    }
}

int main()
{
    int n1,n2;
    int **array,i,j;
    puts("输入一维长度:");
    scanf("%d",&n1);
    puts("输入二维长度:");
    scanf("%d",&n2);
    array=(int**)malloc(n1*sizeof(int*)); //第一维
    for(i=0;i<n1; i++)
    {
        array[i]=(int*)malloc(n2* sizeof(int));//第二维
        for (j=0;j<n2;j++) {
        int q;
        scanf("%d",&q);
        array[i][j] = q;
    }
    puts("");
}

    setZeroes(array,n1,n2);


    for (i=0;i<n1;i++) {
        for (j=0;j<n2;j++) {
            printf("arr[%d][%d] = %d \n",i,j,array[i][j]);
        }
    }

    for(i=0;i<n1;i++)
    {
        free(array[i]);//释放第二维指针
    }
    free(array);//释放第一维指针
    return 0;
}
