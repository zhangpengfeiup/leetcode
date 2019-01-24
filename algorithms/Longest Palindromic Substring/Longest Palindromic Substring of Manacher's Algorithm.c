#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s)
{
    int N = strlen(s);
    if (N == 0) {
        return "";
    }
    if (N == 1) {
        return s;
    }

    N = 2 * N + 1;  // Position count
    int L[N];       // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1;      //centerPosition
    int R = 2;      //centerRightPosition
    int i = 0;      //currentRightPosition
    int iMirror;    //currentLeftPosition
    int expand = -1;
    int diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;

    for (i = 2;i < N;i++) {
        iMirror = 2 * C - i;

        expand = 0;

        diff = R - i;

        if (diff > 0) {
            if (L[iMirror] < diff) {
                L[i] = L[iMirror];
            }else if (L[iMirror] == diff && i == N-1) {
                L[i] = L[iMirror];
            }else if (L[iMirror] == diff && i < N-1) {
                L[i] = L[iMirror];
                expand = 1;
            }else if (L[iMirror] > diff) {
                L[i] = diff;
                expand = 1;
            }
        }else {
            L[i] = 0;
            expand = 1;
        }

        if (expand == 1) {
            while ( (i + L[i]) < N && (i - L[i] > 0) && ( (i + L[i] + 1) %2 ==0 || (s[(i + L[i] + 1)/2]  == s[(i - L[i] - 1)/2] )) ) {
                L[i]++;
            }
        }

        if (L[i] >= maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;

    char *ret;

    ret = calloc(1005,sizeof(char));
    int count = 0;
    int j;
    // assign the from start and maxLen string  to the ret string.
    for (j = start; j <= end; j++)
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

