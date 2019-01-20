#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isPalindromic(char *s,int start,int end)
{

    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}



char* longestPalindrome(char* s)
{
    int i,j,k,len,maxLen,tmpLen;
    bool res;
    len = strlen(s);

    if (len <= 0)
    {
        return "";
    }
    char *ret = (char *)calloc(1001,sizeof(char));
    ret[0] = s[0];
    maxLen = 1;

    for (i = 0; i < len; i++)
    {
        for (j = i+1; j < len; j++)
        {

            res = isPalindromic(s,i,j);
            tmpLen = j - i;

            if (res && tmpLen >= maxLen)
            {
                maxLen = tmpLen;
                int count = 0;
                for (k = i; k <=j; k++)
                {
                    ret[count] = s[k];
                    count++;
                }
            }

        }
    }
    return ret;
}

/*
	for debug you can look it.  it print all sequence.
	And I Mmeet the case of
	Input "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
	
	Output: "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"
	
	Expected "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
	
	在本地调试这个数据没有问题，但是提交到leetcode就是这个错误了，我想应该是malloc 分配空间的时候没有初始化，将malloc 函数换成calloc 就可以解决问题了。
	最后的提交后的结果为912ms，比较慢，但是很开心哈，这道题应该是考查动态规划，如果换成动态规划的话怎么做会比较好呢？我自己想一下，然后找一下资料看看怎么做.
	
	bool isPalindromic(char *s,int start,int end)
{

    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

char* longestPalindrome(char* s)
{
    int i,j,k,len,maxLen,tmpLen;
    bool res;
    len = strlen(s);

    if (len <= 0)
    {
        return NULL;
    }
    char *ret = malloc(sizeof(char) * 1001);
    ret[0] = s[0];
    maxLen = 1;

    for (i = 0; i < len; i++)
    {
        //输出每一个一个字母的时候
        printf("%c\n",s[i]);
        for (j = i+1; j < len; j++)
        {


            for (k = i; k <=j; k++)
            {
                // 可以输出所有的排列
                printf("%c",s[k]);
            }
            printf("\n");
        }
    }
    return ret;
}

	
*/


int main()
{
    char *result = malloc(sizeof(char) * 1001);
    //定义字符串
    char s[] = "babad";

    result = longestPalindrome(s);
    printf("%s",result);
    // 将字符串当作参数传递到函数当中



    return 0;
}



