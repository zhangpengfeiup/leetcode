#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Refer from https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
// Also the Calculation method is below,refer from http://www.cnblogs.com/grandyang/p/4464476.html
/*
    if (i == j)                                   dp[i][j] = 1;
    if (j = i+1 && s[i] == s[j])                  dp[i][j] = 1
    if (s[i] == s[j] && dp[i+1][j-1] && i > j+1)  dp [i][j] = 1
*/

char* longestPalindrome(char* s)
{
    // The time complexity can be reduced by storing results of subproblems.
    int len = strlen(s);

    if (len <= 0)
    {
        return "";
    }
    int i,j,k,start,maxLen;
    char *ret;
    int dp[len][len];

    // why memset set 1,print out not 1?
    // As memset works character by character and an integer cotains more than one bytes(or characters)
    // However,if we replace 10 with -1,we get -1 values.Because representation of -1 contains all 1s in case of both char and int.
    // Refer from https://www.geeksforgeeks.org/memset-c-example/

    memset(dp,0,sizeof(dp));

    /*
    for (i = 0;i < len;i++) {
        for (j = 0;j < len;j++) {
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    */

    // init maxLen,because one char is must Palindromic substring
    start = 0;
    maxLen = 1;

    //init dp when the char is one ,you need careful of here is dp[i][i],not dp[i][0]
    for (i = 0; i < len; i++)
    {
        dp[i][i] = 1;
    }

    // judge adjacent is equal,is equal is true,so maxLen is 2
    // here is len-1 not len
    for (i = 0; i < len - 1; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            start = i;
            maxLen = 2;
        }
    }

    // when >=3
    for (k = 3; k <= len; k++)
    {

        // fix start index
        for (i = 0; i < len-k+1; i++)
        {
            // get the ending index
            j = i + k - 1;

            // if you do not know why is i+1,j-1,you can think delete head and tail,judge it is palindromic substring? this is a sub problem.
            if (dp[i+1][j-1] && s[i] == s[j])
            {
                dp[i][j] = 1;

                if (k >= maxLen)
                {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }

    // for debug
    //printf("maxLen is %d\n",maxLen);
    // printf("start is %d\n",start);

    ret = calloc(1005,sizeof(char));
    int count = 0;
    // assign the from start and maxLen string  to the ret string.
    for (i = start; i < start + maxLen; i++)
    {

        ret[count] = s[i];
        count++;
    }

    return ret;
}

int main()
{
    char s[] = "babad";
    char *ret;
    ret = calloc(1005,sizeof(char));
    ret = longestPalindrome(s);
    printf("%s",ret);

    return 0;
}
