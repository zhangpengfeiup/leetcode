#include <stdio.h>
#include <stdbool.h>


/*
 * This is a math problem. in the beginning i don't know how to revere the number,and how to can know where is the half.
 * After see the solution,get it.You can see the solution of https://leetcode.com/problems/palindrome-number/solution/
 */
bool isPalindrome(int x) {
    int reverseNum = 0;

    if (x < 0 || (x %10 == 0 && x !=0)) {
        return false;
    }

    while (x > reverseNum) {
        reverseNum = reverseNum * 10 + x % 10;
        x = x / 10;
    }

    return x == reverseNum || x == reverseNum / 10;
}

int main() {
    int n;
    bool flag;
    while(scanf("%d",&n) != EOF) {
        flag = isPalindrome(n);
        if (flag) {
            printf("It is palindrome\n");
        }else {
            printf("It is not palindrome\n");
        }
    }
}
