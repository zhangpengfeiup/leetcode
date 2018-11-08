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
        int left=0,right=numSize-1,ret;
        ret=num[0];
        while (left < right-1) {
            int mid = (left + right) / 2;
            // mid right is increment
            if (num[mid] < num [right]) {
                ret = min(num[mid],ret);
                right = mid;
            }else if (num[mid] > num[left]) {  // mid left is increment
                ret = min(num[left],ret);
                left = mid;
            }else {
                left ++;
            }
        }
        ret =  min(num[left],ret);
        ret = min(num[right],ret);
        return ret;
}

int main() {
     int arr[] = {1,3,3};
    int ret;
    ret = findMin(arr,3);
    printf("the min is %d\n",ret);
    return 0;

}
