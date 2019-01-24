#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this is my first idea question
char* convert(char *s,int numRows)
{
    //异常处理
    if (numRows <= 1)
    {
        return s;
    }


    int len,column,group,circleLength,circleColumn;
    len = strlen(s);

    if (len <= 1) {
        return s;
    }

    char *result;

    //折返跑一样 需要几个折返跑,一去一回是一个折返跑

    //这是一个折返跑占的列数
    group = (numRows - 2) + 1; //numRows=4 一个来回是3列，numRows=3,一个来回是2列

    // 一个折返跑多少个字符呀,因为返回的时候除了首尾所以减去2
    circleLength = numRows + numRows -2;

    // circleColumn 需要多少个单位的折返跑
    circleColumn = len / circleLength;
    if (len % circleLength)
    {
        circleColumn = circleColumn + 1;
    }
    //column 需要的列数
    column = circleColumn * group;

    // 开辟二维字符数组
    int i,j;
    char **ret;
    ret = malloc(numRows * sizeof(char *));
    for (i = 0; i < numRows; i++)
    {
        ret[i] = malloc(column * sizeof(char));
        for (j = 0 ; j < column; j++)
        {
            ret[i][j] = 0;
        }
    }


    int currentColumn = 0;
    int count = 0;
    for (i = 0; i < circleColumn; i++)
    {

        if (count == len)
        {
            break;
        }

        int currentRow = 0;

        for (j = 0; j < numRows; j++)
        {
            if (count == len)
            {
                break;
            }
            ret[currentRow][currentColumn] = s[count++];

            if (j != numRows - 1)
            {
                currentRow++;
            }
        }

        for (j = 0; j < numRows - 2; j++)
        {
            if (count == len)
            {
                break;
            }
            ret[--currentRow][++currentColumn] = s[count++];
        }
        ++currentColumn;
    }



    /*
    for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < column; j++)
        {

                printf("%c ",ret[i][j]);


        }
        printf("\n");
    }

    */
   int tmp = 0;
    result = malloc(sizeof(char) * len+1);

     for (i = 0; i < numRows; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (ret[i][j] != 0) {
                result[tmp++] = ret[i][j];
            }
        }
    }
    // you need add the end of string. otherwise it will end of other string of answer.
    result[len] = '\0';

    return result;

}
// this is a wonderful idea,you can refer to https://www.cnblogs.com/TenosDoIt/p/3738693.html
char* convert2(char *s,int numRows)
{
    if (numRows == 1) {
        return s;
    }
    int len = strlen(s);
    int count = 0;
    int size = 2 * numRows - 2;
    char *ret;
    ret = malloc(sizeof(char) * len+1);

    int i,j;
    for (i = 0;i < len;i += size) {  //第一行
        ret[count++] = s[i];
    }

    //中间行
    for (i = 1;i < numRows -1;i++) {
         int inter = i * 2;
         // here is wonderful,inter,size-inter,inter,size-inter is repeat
         for (j = i;j < len;j += inter) {
            ret[count++] = s[j];
            inter = size - inter;
         }
    }

    // 处理最后一行
    for (j = numRows -1;j < len;j+=size) {
        ret[count++] = s[j];
    }

    ret[len] = '\0';
    return ret;
}

int main()
{
    char *s = "PAYPALISHIRING";
    char *ret;
    ret = convert2(s,3);
    printf("%s",ret);

    return 0;
}
