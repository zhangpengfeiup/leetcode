#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums,int numsSize) {
    int i,j;
    if (numsSize <=0) {
        return 0;
    }
    i=0;
   for (j=0;j<numsSize;j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
   }
   return i+1;
}

int main() {
    int num;
    scanf("%d",&num);
    int *array = malloc(num*sizeof(int));
    int i,value,len;
    for (i=0;i<num;i++) {
        scanf("%d",&value);
        array[i] = value;
    }
    len = removeDuplicates(array,num);
    printf("%d\n",len);
    return 0;
}
