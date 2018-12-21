#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count(int n) {
    int tmp;
    int sum = 0;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n = n/10;
    }
    return sum;
}

/*
    use the array to make up the hash set to judge the num has apper?
    the other method is use fast slow pointer to judge it has the cycle?

    From the problem,i know we should from the problem, abstract out the appropriate scenarios.Then use the method of useful to deal with it.
*/
bool isHappy(int n) {
    int capcacity = 5000;
    int *arr = calloc(capcacity,sizeof(int));
    int ret;
    while (ret != 1) {
       ret = count(n);
       if (ret == 1) {
          return true;
       }else {
        if (arr[ret] == 1) {
             return false;
        }
        arr[ret] = 1;
        n = ret;
      }
    }
    return false;
}

//fast slow pointer


/*
bool isHappy(int n) {
    int fast,slow;
    slow = count(n);
    fast = count(n);
    while(true) {
         slow = count(slow);
        fast = count(fast);
        fast = count(fast);
        if (slow == 1) {
            return true;
        }
        if (slow == fast) {
            return false;
        }
    }
}
*/


int main()
{
    int num;
    bool flag;
    while (scanf("%d",&num)!=EOF) {
        flag = isHappy(num);
        if (flag) {
            printf("true");
        }else {
            printf("false");
        }
    }
    return 0;
}
