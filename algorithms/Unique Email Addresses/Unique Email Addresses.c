#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
int numUniqueEmails(char** emails,int emailsSize) {
    char unique[100][100] = {0};

    char email[100] = {0};

    int uniqueSize = 0;
    int keepon;
    int found;
    int i,j,k;

    for (i = 0;i < emailsSize; i++) {
        //@ 前面的逗号去掉，+号后面的也去掉，然后看是否重复
        keepon = 1;
        k = 0;
        j = 0;
        found = 0;
        while(emails[i][j] != '@') {

            if (emails[i][j] == '+') {
                keepon = 0;
            }else if (keepon && emails[i][j] != '.') {
                email[k++] = emails[i][j];
            }
           j++;
        }

        while (emails[i][j]) {
            email[k++] = emails[i][j++];
        }

        email[k] = '\0';
        int u;
        for (u = 0;u < uniqueSize && !found; u++) {
            if (strcmp(unique[u], email) == 0) {
                found = 1;
            }
        }

        if (!found) {
            strcpy(unique[uniqueSize++],email);
        }
    }
    return uniqueSize;
}

int main()
{
    //the point array to stand for the string of array.
    char *emails[] = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};

    int num;
    int count;
    num = sizeof(emails)/sizeof(emails[0]);


    count = numUniqueEmails(emails,num);
    printf("%d\n",count);
    return 0;
}
