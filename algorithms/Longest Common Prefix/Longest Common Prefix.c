#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs,int strsSize) {
    if (strsSize <= 0) {
        return "";
    }
    int i,j,l=0;
    int len = strlen(strs[0]);
    char *ret = (char *)malloc(sizeof(char) * len + 1);

    // strs[0][0] strs[1][0] strs[2][0]

    for (i = 0;i < len;i++) {
        for (j = 0;j < strsSize;j++) {
            if (strs[0][i] != strs[j][i]) {
                 ret[l] = '\0';
                 return ret;
            }
        }
        ret[l++] = strs[0][i];
    }
    ret[l] = '\0';
    return ret;
}

int main()
{
    char *ret = (char *)malloc(sizeof(char) * 100);
    char *strs[] = {"flower","flow","flight"};
    ret = longestCommonPrefix(strs,3);
    printf("%s\n",ret);
    return 0;
}
