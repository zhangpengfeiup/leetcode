#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// refer to https://leetcode.com/problems/word-pattern/discuss/155714/0ms-C-Solution/197891

// the c point i can not write it right.so you can read it. i have write the comments on it,hope it useful to you.

bool wordPattern(char* pattern, char* str) {
    int str_len = strlen(str);
    char buffer[str_len+1];
    //复制字符串到buffer中
    strcpy(buffer, str);

    char *p = pattern;
    //使用函数strtok进行函数分隔
    char *s = strtok(buffer," ");
    //定义指针数组,因为都是小写字母，所以长度是26,指针数组存放的是字符串的地址
    char *table[26];

    //初始化table 数组
    memset(table,'\0',26 * sizeof(char *));

    do {
        //如果p为空字符串,字符串是以'\0' 结束的
        if (*p == '\0') {
            return false;
        }
        //取出p的值减去字符a获取到数组中对应的下标值，然后*P++
        int input = *p++ - 'a';
        int i;
        if (table[input] == NULL) {

            for (i=0;i<26;i++) {
                if (table[i] == NULL)
                    continue;
                // 如果除了input地址外还有其他与s相等的字符串，返回false
                if (strcmp(table[i], s) == 0) {
                    return false;
                }
            }

            table[input] = (char *)malloc((strlen(s)+1) *sizeof (char));
            strcpy(table[input],s);
        } else {
            //如果input不为空还和s不相等,return false
            if (strcmp(table[input],s)) {
                return false;
            }
        }

        s = strtok(NULL, " ");
    }while (s != NULL);
    //释放开辟的空间
    int i;
    for (i=0;i<26;i++)
        free(table[i]);

     if (*p != '\0') {
        return false;
    }
    return true;
}

int main() {
    char pattern[] = "abba";
    char str[] = "dog cat cat dog";
    bool flag;
    flag = wordPattern(pattern,str);
    if (flag) {
        printf("ok\n");
    }else {
        printf("fail\n");
    }
    return 0;
}
