#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isChar(char *c) {
    if (*c >= '0' && *c <= '9') return true;
    if (*c >= 'A' && *c <= 'Z') return true;
    if (*c >= 'a' && *c <= 'z') return true;
    return false;
}


bool isPalindrome(char *s) {
    int len = strlen(s);
    if (!len)
        return true;
    char *p1 =s,*p2 = s+len-1;
    while(p1 < p2) {
        if (!isChar(p1)) {
            p1++;
            continue;
        }

        if (!isChar(p2)) {
            p2--;
            continue;
        }

        if (towlower(*p1++) != towlower(*p2--)) {
            return false;
        }
    }
    return true;
}

int main()
{
    char *s = "A man, a plan, a canal: Panama";
    bool ret;



    ret = isPalindrome(s);
    if (ret) {
        printf("yeah");
    }else {
        printf("no");
    }

}
