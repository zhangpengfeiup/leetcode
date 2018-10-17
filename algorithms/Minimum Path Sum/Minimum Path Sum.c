#include <stdio.h>
#include <stdlib.h>

int mins(int a,int b) {
    if (a>b) {
        return b;
    }else {
        return a;
    }
}

//print all sum from top left to bottom right
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int dp[gridRowSize][gridColSize];
    int i,j;
    dp[0][0] = grid[0][0];
    for (i=1;i<gridColSize;i++) {
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }

    for (j=1;j<gridRowSize;j++) {
        dp[j][0] = grid[j][0] + dp[j-1][0];
    }
    for (i=1;i<gridRowSize;i++) {
        for (j=1;j<gridColSize;j++) {
            dp[i][j] = mins(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[gridRowSize-1][gridColSize-1];
}


int main()
{
    int row,col,i,j,val,minSum;
    int **array;
    puts("输入一维长度");
    scanf("%d",&row);
    puts("输入二维长度");
    scanf("%d",&col);
    array=(int**)malloc(row*sizeof(int*));
    for(i=0;i<row;i++) {
        array[i] = (int*)malloc(col*sizeof(int));
        for (j=0;j<col;j++) {
            printf("请输入array[%d][%d] 的值",i,j);
            scanf("%d",&val);
            array[i][j] = val;
        }
    }
    minSum = minPathSum(array,row,col);
    printf("%d\n",minSum);
    return 0;
}
