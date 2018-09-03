#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a,const void *b) {
     return *(int *) a - *(int *) b;
}


int threeSumCloest(int* nums,int numsSize,int target) {
    qsort(nums,numsSize,sizeof(int),compare);
    int i,j,z,gap,sum,ret;
    gap = INT_MAX;

    for (i=0;i<numsSize;i++) {
        for (j=i+1;j<numsSize;j++) {
            for (z=j+1;z<numsSize;z++) {
                sum = nums[i] + nums[j] + nums[z];
                printf("%d \n",sum);
                if (abs(sum - target) < gap) {
                    gap = abs(sum-target);
                    ret = sum;
                }
            }
        }
    }

   return ret;
}

int main()
{
    int nums[]={-1,2,1,-4};
    int length;

    length=sizeof(nums)/sizeof(int);

    int c;
    int target = 1;
    c = threeSumCloest(nums,length,target);
    printf("the position  value is %d\n",c);
    return 0;
}

/**
	first i think can use the between of the three num can traverse the array. We can use O(n),
	But it is wront answer.
	After I think, it is find 3 sum cloest,if I do it, It will not find some result.
	The wrong idea is as follow. It should be: I do not understand the problem.
	
	 int threeSumClosest(int* nums, int numsSize, int target) {
		 if (numsSize < 0) {
			return 0;
		}
		int i,z,left,right,sum,gap,leftValue,rightValue;
		gap = abs(nums[0]-target);
		z = 0;
		for (i = 0;i < numsSize;i++) {
			left=i-1;
			right=i+1;
			if (left < 0) {
				leftValue = 0;
			}else {
				leftValue = nums[left];
			}
			if (right > numsSize-1) {
				rightValue = 0;
			}else {
				rightValue = nums[right];
			}
			sum = leftValue+nums[i]+rightValue;
			if (abs(sum - target) < gap) {
			   z = sum;
			}
		}
		return z;
	}
**/
