#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool dfs(char **board,int boardRowSize,int boardColSize,char *word,int len,int searchLen,int curRow,int curCol,bool **status)
{

    //递归终止条件
    if (searchLen == len)
    {
        return true;
    }
    // 判断参数是否合法
    if (curRow >= boardRowSize  || curCol >= boardColSize ||  curRow < 0 || curCol < 0 || status[curRow][curCol] || board[curRow][curCol] != word[searchLen])
    {
        return false;
    }


    //使用status 数组作为备忘录
    status[curRow][curCol] = true;

    bool res = dfs(board,boardRowSize,boardColSize,word,len,searchLen+1,curRow+1,curCol,status) ||
               dfs(board,boardRowSize,boardColSize,word,len,searchLen+1,curRow-1,curCol,status) ||
               dfs(board,boardRowSize,boardColSize,word,len,searchLen+1,curRow,curCol+1,status) ||
               dfs(board,boardRowSize,boardColSize,word,len,searchLen+1,curRow,curCol-1,status);
    status[curRow][curCol] = false;


    return res;
}

 
//形参为指针的指针，实参必须为指针   
bool exist(char** board,int boardRowSize,int boardColSize,char* word)
{
    int len = strlen(word);
    int i,j;

     bool **status;
    status = (bool **)malloc(boardRowSize * sizeof(bool *));
    for (i=0;i<boardRowSize;i++) {
        status[i] = (bool *)malloc(boardColSize*sizeof(bool));
        memset(status[i],false,boardColSize*sizeof(bool));
    }

    for (i = 0; i< boardRowSize; i++)
    {
        for (j = 0; j<boardColSize; j++)
        {
            if (dfs(board,boardRowSize,boardColSize,word,len,0,i,j,status))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // how to init the string array.and how to print it.
    char board[4][4] =
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    char *a[4];
    a[0] = board[0];
    a[1] = board[1];
    a[2] = board[2];
    a[3] = board[3];

    char *word = "ABCCED";
    bool ret = exist(a,4,4,word);

    if (ret) {
        printf("find\n");
    }else {
        printf("no find\n");
    }

    printf("Hello world!\n");
    return 0;
}
