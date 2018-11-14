#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//refer to the http://www.cnblogs.com/grandyang/p/4462810.html

int countPrimes(int n) {
    int i,j,count=0;
   
    int *arr;
	//malloc n size array
    arr = (int *)malloc(n*sizeof(int));

    memset(arr,0,n*sizeof(int));

    int len = sqrt(n);

    for (i=2;i<=len;i++) {
        // i = 2,the array value is arr[1],so is the arr[i-1]     
        if (arr[i-1] == 0) {
            for (j=i*i;j<n;j+=i) {
                arr[j-1] = 1;
            }
        }
    }

    for (i=2;i<n;i++) {

            printf("%d ",arr[i]);
        if(arr[i] == 0) {
            count++;
        }
    }
    return count;
}

int main()
{
    int n=10,ret;
    ret = countPrimes(n);
    printf("%d\n",ret);
    return 0;
}
