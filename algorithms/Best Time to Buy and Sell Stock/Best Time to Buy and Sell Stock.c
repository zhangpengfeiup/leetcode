#include <stdio.h>
#include <stdlib.h>

// O (n*n)
// When you have writed  a code,ask yourself,have a better method to solve it?

/*
int maxProfit(int* prices, int pricesSize) {
    int i,j;
    int maxProfit = 0;
    for (i = 0;i<pricesSize;i++) {
        for (j = i+1;j<pricesSize;j++) {
            if (prices[j] - prices[i] > maxProfit) {
                maxProfit = prices[j] - prices[i];
            }
        }
    }
    return maxProfit;
}
*/

// O (n)
int maxProfit(int* prices, int pricesSize) {
    int i;
    int maxProfit = 0;
    int minNum = prices[0];
    for (i = 1;i<pricesSize;i++) {
        if (prices[i] - minNum > maxProfit) {
            maxProfit = prices[i] - minNum;
        }
        if (prices[i] < minNum) {
            minNum = prices[i];
        }
    }
    return maxProfit;
}



int main()
{
    int n = 6;
    int *array = (int *)malloc(n * sizeof(int));
    array[0] = 7;
    array[1] = 1;
    array[2] = 5;
    array[3] = 3;
    array[4] = 6;
    array[5] = 4;

    int ret;
    ret = maxProfit(array,6);
    printf("%d\n",ret);
    return 0;
}
