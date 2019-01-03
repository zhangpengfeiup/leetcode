#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// It is mine solution, the time complexity is O(n*n*n)
int lengthOfLongestSubstring(char* s)
{
    int i,j,len,count = 0;
    len = strlen(s);
    if (len == 1)
    {
        return 1;
    }
    int *hash = (int *)malloc(128 *sizeof(int));

    for (i = 0; i<len; i++)
    {
        int tmp = 0;
        memset(hash,0,128*sizeof(int));
        for (j=i; j<len; j++)
        {
            int key = s[j];

            if (hash[key] == 1)
            {
                break;
            }
            if (hash[key] == 0)
            {
                tmp++;
                hash[key] = 1;
            }
        }
        if (tmp > count)
        {
            count = tmp;
        }

    }
    return count;
}

int main()
{
    char *s = "abcabcbb";
    //char *s = "";
    //char *s = "bbb";
    // char *s = "ilfyhpbwmdm";
    int ret;
    ret = lengthOfLongestSubstring(s);
    printf("%d",ret);
    return 0;
}
