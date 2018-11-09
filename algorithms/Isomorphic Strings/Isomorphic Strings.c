#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    hash table
*/

bool isIsomorphic(char* s,char* t) {
    int arr[256] = {0};
    int brr[256] = {0};
    int i = 0;
    while (*s && *t) {
     if (arr[*s] != brr[*t]) {
          return false;
       }
        arr[*s] = i+1;    // here i+1 is to assure to the same position have the same value.you can try it
        brr[*t] = i+1;
        i++;
        *s++;
        *t++;
    }
    return true;
}

int main() {
   char *s = "aba";
   char *t = "baa";
   bool ret;
    ret = isIsomorphic(s,t);
    if (ret) {
        printf("success\n");
    }else {
        printf("no success\n");
    }

}
