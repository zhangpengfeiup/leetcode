#include <stdio.h>
#include <stdlib.h>


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int dp[obstacleGridRowSize][obstacleGridColSize];
    int i,j;
    for (i=0;i<obstacleGridRowSize;i++) {
        for (j=0;j<obstacleGridColSize;j++) {
             // touch the stone
            if(obstacleGrid[i][j] == 1) {
                dp[i][j]= 0;
            }
            else if (i==0 && j==0) {
                dp[i][j] = 1;
            }
            else if (i==0 && j>0) {
                 dp[i][j] = dp[i][j-1];
            }
            else if (j==0 && i>0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[obstacleGridRowSize-1][obstacleGridColSize-1];
}

int main()
{
    int row,col,i,j,val,paths;
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
    paths = uniquePathsWithObstacles(array,row,col);
    printf("%d \n",paths);
    return 0;
}
