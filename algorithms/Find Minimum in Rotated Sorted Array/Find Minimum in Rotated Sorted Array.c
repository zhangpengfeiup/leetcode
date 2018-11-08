#include <stdio.h>


/*
	the problem we need know the mid left is increment or right is increment
	if you know it.you can write the code.
*/

int min(int a,int b) {
    return a > b?b:a;
}

int findMin(int *num,int numSize)
{
    int left=0,right=numSize-1,mid;
	if (num[left] > num[right]) {
		while (left < (right-1)) {
			mid = (left+right)/2;
			 if (num[mid] < num [right]) {
				right = mid;
			}else if (num[mid] > num[left]) {  // mid left is increment
				left = mid;
			}
		}
		return min(num[left],num[right]);
   }
    return num[0];
}

int main() {
     int arr[] = {4,5,6,7,0,1,2};
    int ret;
    ret = findMin(arr,7);
    printf("the min is %d\n",ret);
    return 0;
}
