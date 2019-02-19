#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int changeInt(char a) {
    if (a == 'M') {
        return 1000;
    }

    if (a == 'D') {
        return 500;
    }
     if (a == 'C') {
        return 100;
    }

     if (a == 'L') {
        return 50;
    }

    if (a == 'X') {
        return 10;
    }

     if (a == 'V') {
        return 5;
    }

    if (a == 'I') {
        return 1;
    }

    return 0;
}

int romanToInt(char* s) {

    int ret = 0;
    int i,len;
    len = strlen(s);

    for (i = 0;i < len;i++) {
        int cur = changeInt(s[i]);
        int next = changeInt(s[i+1]);
        if(cur >= next) {
            ret += cur;
        }else {
            ret = ret + (next-cur);
            i++;                     // 这个时候是两个字符计算一个数据，所有i++,以后执行for循环的i++
        }
    }
    return ret;
}

int main()
{
    char str[10];
    int ret;
    while(scanf("%s",str)) {
        ret = romanToInt(str);
        printf("%d\n",ret);
    }

    return 0;
}
