#include <stdio.h>
#include <stdlib.h>

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

// what is the Game of life. you can find it from https://zh.wikipedia.org/wiki/%E5%BA%B7%E5%A8%81%E7%94%9F%E5%91%BD%E6%B8%B8%E6%88%8F
// Refer to https://www.cnblogs.com/grandyang/p/4854466.html

/*
   in the problem, you need the status from the problem.
   and need careful to the variable change and define.
   Also i find the array can contian many different things.
 */
void gameOfLife(int** board, int boardRowSize, int *boardColSizes) {
    int i,j,k,x,y,count;

    for (i=0;i<boardRowSize;i++) {
        for (j=0;j<*boardColSizes;j++) {
            count = 0;
            for (k=0;k<8;k++) {
                x = i+dx[k];
                y = j+dy[k];
                if (x <0 || x >= boardRowSize || y <0 || y >= *boardColSizes) {
                    continue;
                }
                if (board[x][y] == 1 || board[x][y] == 2) {
                    count++;
                }
            }

            if (board[i][j] && (count < 2 || count >3)) {
                board[i][j] = 2;
            } else if (!board[i][j] && count == 3) {
                board[i][j] = 3;
            }
        }
    }

    for (i=0;i<boardRowSize;i++) {
        for (j=0;j<*boardColSizes;j++) {
            board[i][j] %=2;
        }
    }
}

void gameOfLife2(int** board, int boardRowSize, int *boardColSizes) {
    printf("%d",*boardColSizes);
}

int main()
{
    int **board;
    int m,n,i,j,value;


    scanf("%d %d",&m,&n);
    board = malloc(m*sizeof(int*));
    for (i=0;i<m;i++) {
        board[i] = malloc(n*sizeof(int));
        for (j=0;j<n;j++) {
            scanf("%d",&value);
            board[i][j] = value;
        }
    }

    gameOfLife(board,m,&n);

    printf("Hello world\n");
    return 0;
}
