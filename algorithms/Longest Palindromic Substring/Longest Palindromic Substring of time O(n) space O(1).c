#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Step to generate odd length palindrome:
    Fix a centre and expand in both directions for longer palindromes.

    Step to generate even length palindrome.
    Fix two centre (low and high) and expand in both directions for longer palindromes.
    It use (n * n) time and With O(1)

    Refer from https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
*/

char* longestPalindrome(char* s)
{
    int len = strlen(s);
    int start = 0;
    int maxLen = 1;
    int i,j;
    int low,high;
    char *ret;
    for (i = 1; i < len; i++)
    {

        // even length
        low = i - 1;
        high = i;

        while (low >=0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 >= maxLen)
            {
                start = low;
                maxLen = high - low + 1;
            }
            // expand the length
            low--;
            high++;
        }


        // odd length
        low = i - 1;
        high = i + 1;

        while (low >=0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 >= maxLen)
            {
                start = low;
                maxLen = high - low + 1;
            }
            // expand the length
            low--;
            high++;
        }

    }


    ret = calloc(1005,sizeof(char));
    int count = 0;
    // assign the from start and maxLen string  to the ret string.
    for (j = start; j < start + maxLen; j++)
    {

        ret[count] = s[j];
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
