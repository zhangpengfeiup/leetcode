#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAnagram(char *s,char *t) {
    int lens,lent;
    lens = strlen(s);
    lent = strlen(t);
    int i,index;

    if (lens != lent) {
        return false;
    }

    int a[26] = {0};
    for (i = 0;i < lens;i++) {
        index = s[i] - 'a';
        a[index]++;
    }

    for (i = 0;i < lent;i++) {
        index = t[i] - 'a';
        a[index]--;
    }

    for (i = 0;i<26;i++) {
        if (a[i] != 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    char s[10] = "anagram";
    char t[10] = "nagaram";
    bool flag = isAnagram(s,t);
    if (flag) {
        printf("111");
    }else {
        printf("000");
    }
    return 0;
}
