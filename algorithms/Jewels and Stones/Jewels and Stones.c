#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// if i define int hash [1000] = {0} is global, leetcode will be wrong
// I could not know how it happen.

int numJewelsInStones(char* J,char* S) {

    int count = 0;
    int i;
    int hash[1000] = {0};
    int numJ = strlen(J);
    int numS = strlen(S);

    for (i = 0;i < numJ; i++) {
        hash[ (int)J[i] ] = 1;
    }

    for (i = 0;i < numS; i++) {
        if (hash[ (int)S[i] ]) {
            count++;
        }
    }
    return count;
}

// not hash
/*
    int numJewelsInStones(char *J,char *S) {
        int count = 0;
        for (;*S != '\0'; *S++) {
            char *j = J;
            for (;*j != '\0'; *j++) {
                    printf("1 ");
                if (*S == *j) {
                    count++;
                }
            }
        }
        return count;
    }
*/
int main()
{
    char J[] = "bcd";
    char S[] = "cba";
    int count;
    count = numJewelsInStones(J,S);
    printf("%d", count);

    return 0;
}
