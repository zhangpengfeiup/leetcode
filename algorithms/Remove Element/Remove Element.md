下面是我的解法，我一开始想的是交换，因为题目要求空间复杂度是O(1),所以我想的是从前往后查找，如果等于val的值，从后往前查找不等于val的第一个值，然后进行交换，low++,hign--,感觉和快排的思想有点相似，在这个过程中，我也理解了为什么快排中的每个while循环判断中都加入while(low <= high) 这种判断，因为不加入这种判断，程序会接着执行，并没有跳出去。

在这个题目中，虽然题目是不难的，但是调试的时候还是漏了很多种情况，提交了好几次，同时在这个过程中，也认识到了自己做题的错误的想法，现阶段感觉应该这样的思路去做题:

如何做LeetCode上的题呢？
1. 首先在纸上把伪代码写出来，将题目思路理解清楚
2. 使用题目中的case将自己的伪代码在脑子中跑一下，看看有没有其他没有考虑到的情况
3. 如果上面的都可以的话，然后自己写测试用例，也就是多造几个case，特别是空的还有不经常出现的，然后进行测试。
4. 然后都没有问题了再进行提交。

看了一下最优解: 
还是比较方便的，只要不等于val的值，直接覆盖前面的变量，还有一个变量记录下标的变化，相当于游标，往后进行移动。
代码在下面：可以参考一下

```
#include <stdio.h>
#include <stdlib.h>

void change(int *nums,int low,int high) {
    int temp;
    temp = nums[high];
    nums[high] = nums[low];
    nums[low] = temp;
}

int removeElement(int* nums,int numsSize,int val) {
    int low,high;
    low = 0;
    high = numsSize - 1;
    while (low <= high) {
        if (nums[low] == val) {
            if (low == high) {
                numsSize--;
                return numsSize;
            }
            while(nums[high] == val && low <= high) {
                numsSize--;
                high--;
                if (numsSize == 0) {
                    return 0;
                }
            }
            if (high >= 0 && low <= high) {
                change(nums,low,high);
                numsSize--;
                low++;
                high--;
            }
        }else {
            low++;
        }
    }
    return numsSize;
}

int main()
{
    int num;
    puts("请输入数组的长度");
    scanf("%d",&num);
    int *nums = malloc(num * sizeof(int));
    int i;
    puts("请输入数组的值");
    for (i = 0;i < num;i++) {
        scanf("%d",&nums[i]);
    }
    int val;
    puts("请输入val的值");
    scanf("%d",&val);
    int ret;
    ret = removeElement(nums,num,val);
    printf("ret is %d\n",ret);
    return 0;
}
```

最优解如下代码所示:

```
int removeElement(int* nums, int numsSize, int val) {
    if (!numsSize) return numsSize;
    
    int result = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[result++] = nums[i];
        }
    }
    
    return result;
}
```