#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void dfs(char *digits,int level,int *returnSize,char **ret,char *curStr) {
    int end = strlen(digits);
    if (level == end) {
        ret[*returnSize] = malloc(sizeof(char) * strlen(curStr) + 1);
        strcpy(ret[*returnSize],curStr);
        (*returnSize)++;
        return;
        // 放入到存储空间当中，需要看是否需要分配存储空间
    }
    char letterCom[][9] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char str[10];
    int index = digits[level] - '0';
    strcpy(str,letterCom[index]);
    int j;
    for (j = 0;j < strlen(str);j++) {
        curStr[level] = str[j];
        dfs(digits,level+1,returnSize,ret,curStr);
    }
}

char** letterCombinations(char* digits,int *returnSize) {
    // need length represent end,
    int level = 0;
    int len = strlen(digits);

    char **ret = malloc(90000 * sizeof(char *));

    if (len <= 0) {
        return ret;
    }
    *returnSize = 0;
    char *curStr = malloc(len+1 * sizeof(char));
    // it need memset curStr,otherwise it will heap-buffer-overflow
    //  Refer to https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8445/Pure-C-recursive-solution
    memset(curStr,0,len + 1);
    dfs(digits,level,returnSize,ret,curStr);
    return ret;
}

int main()
{
    char digits[10];
    int i,size;
    char **ret;
    while(scanf("%s",digits) != EOF) {
        ret = letterCombinations(digits,&size);
        for (i = 0;i < size;i++) {
            printf("%s\n",ret[i]);
        }
         printf("%d\n",size);
    }
    return 0;
}
