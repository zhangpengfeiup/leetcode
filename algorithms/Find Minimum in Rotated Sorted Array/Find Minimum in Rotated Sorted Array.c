/*
	int the while loop, if and else if have '>=' and '<=',i can not tell how?
	if you know,can tell me,thanks.I write it from test case.
*/

#include <stdio.h>
int findMin(int *num,int numSize)
{
    int theMin,low=0,high=numSize-1,mid;
     theMin =  num[0];
    while (low <= high) {
        mid = (low+high)/2;
        if (num[mid] <= num[high]) {
            if (num[mid] < theMin){
                theMin=num[mid];
            }
            high = mid-1;
        }else if (num[mid] >= num[low]) {
            if (num[low] < theMin) {
                theMin = num[low];
            }
            low = mid+1;
        }

    }
    return theMin;
}

int main() {
     int arr[] = {3,4,5,1,2};
    int ret;
    ret = findMin(arr,5);
    printf("the min is %d\n",ret);
    return 0;
}
