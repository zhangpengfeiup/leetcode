#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// this is my solution,2532 ms ,i want laugh to cry.
int reverse(int x)
{

    // 因为 2^31 次方大概是 10 ^9 次方，也就是最多10位数，我们使用20长度的数组已经足够了
    int *arr = calloc(20,sizeof(int));

   // int i;

    int flag = 0;
    // 对负数进行标记
    if (x < 0)
    {
        flag = 1;
        x = x * -1;
    }
     int count = 0;
    // 如何终止循环，当余数和得到的除数都为0的时候，终止循环
    while (x /10 || x % 10)
    {
        // 将得到的余数存储到数组当中
        arr[count] = x % 10;
        x = x / 10;
        count++;
    }


    /*
    for (i = 0;i < 20;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    */
    int tmp;
    // here need long int not int
    long int ret=0;
     tmp = count;
     // here need long int not int
    long int plus = 1;

    //使用tmp =count 来计算需要乘数的大小
    while (--tmp)
    {
        plus = plus * 10;
    }

    long int z = 0;
    while(count)
    {
        ret += arr[z] * plus;
        plus = plus / 10;
        count--;
        z++;
    }
    if (flag)
    {
        ret = ret * -1;
    }

    if(ret>pow(2,31)-1||ret<-pow(2,31))
    {
        return 0;
    }


    return ret;

}

// it is a short and nice code. It refer from https://leetcode.com/problems/reverse-integer/discuss/213733/Reverse-integer-in-C
int reverse1(int x) {
    long ret = 0;
    while(x!=0) {
        ret = ret * 10 + x % 10;
        x = x /10;
    }
    if (ret >pow(2,31)-1 || ret < pow(2,31) * -1) {
        return 0;
    }
    return ret;
}

int main()
{
    int ret;
    int x;

    while(scanf("%d",&x) != EOF)
    {
        ret = reverse1(x);
        printf("%d\n",ret);
    }
    return 0;
}
