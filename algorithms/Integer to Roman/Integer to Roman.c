#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Refer to http://www.cnblogs.com/grandyang/p/4123374.html
char* intToRoman(int num) {
    int i,j;
    int nums[7] = {1000,500,100,50,10,5,1};
    char roman[8] = "MDCLXVI";
    char *ret = (char *)malloc(sizeof(char) * 10);
    char *head = ret;

    for (i = 0; i < 7;i+=2) {
        int tmp;
        tmp = num / nums[i];

        if (tmp < 4) {
            for ( j = 1;j <= tmp;j++) {
                *ret++ = roman[i];
            }
        }else if (tmp == 4) {
            *ret++ = roman[i];
            *ret++ = roman[i-1];
        }else if (tmp > 4 && tmp <9) {
            *ret++ = roman[i-1];
            for (j = 6;j <= tmp;j++) {
                *ret++ = roman[i];
            }
        }else if (tmp == 9) {
            *ret++ = roman[i];
            *ret++ = roman[i - 2];
        }
        num %= nums[i];
    }
    *ret = '\0';
    return head;
}

char* intToRoman2(int num) {
    char *ret = (char *)malloc(sizeof(char) * 10);
    char *head = ret;
    int nums[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	// 指向字符串的指针的数组
    char *roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i,j;
    for (i = 0;i < 13;i++) {
        while (num >= nums[i]) {
            num -= nums[i];
            int len = strlen(roman[i]);
            for (j = 0;j < len;j++) {
                *ret++ = roman[i][j];
            }
        }
    }
    *ret = '\0';
    return head;
}

char* intToRoman3(int num) {
    char *ret = (char *)malloc(sizeof(char) * 10);
    char *head = ret;

    char *roman1[] = {"", "M", "MM", "MMM"};
    char *roman2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *roman3[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *roman4[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char *ret1;
    char *ret2;
    char *ret3;
    char *ret4;
    ret1 = roman1[num/1000];
    ret2 = roman2[(num % 1000)/100];
    ret3 = roman3[(num %100) / 10];
    ret4 = roman4[num % 10];
    int len1 = strlen(ret1);
    int len2 = strlen(ret2);
    int len3 = strlen(ret3);
    int len4 = strlen(ret4);
    int i;
    if (len1 > 0) {
        for (i = 0;i <len1;i++) {
            *ret++ = ret1[i];
        }
    }

    if (len2 > 0) {
        for (i = 0;i <len2;i++) {
            *ret++ = ret2[i];
        }
    }

    if (len3 > 0) {
        for (i = 0;i <len3;i++) {
            *ret++ = ret3[i];
        }
    }

    if (len4 > 0) {
        for (i = 0;i <len4;i++) {
            *ret++ = ret4[i];
        }
    }

    *ret = '\0';
    return head;
}

int main()
{
    int n;
    char *result;
    while (scanf("%d",&n)!= EOF) {
        result = intToRoman(n);
        printf("%s\n",result);
    }
    return 0;
}
