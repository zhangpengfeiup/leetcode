#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
    return true/false
	this is my solution.
	Beside,you can refer to http://www.cnblogs.com/grandyang/p/4371526.html
	I learn from to it.Good Lucky For you!
**/
int max(int a,int b) {
    if (a > b) {
        return a;
    }else {
        return b;
    }
}

bool canJump(int* nums,int numsSize) {
    int i;
    int reach=0;
    for (i=0;i<numsSize && i<=reach;i++) {
        reach = max(reach,i+nums[i]);
         if (reach >= numsSize-1) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {0};
    int length;
    bool ret;
    length = sizeof(nums) / sizeof(int);
    ret = canJump(nums,length);
    if (ret) {
        printf("this is good way! wonderful");
    }else {
        printf("you can think other ways");
    }
    return 0;
}
