#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


/*
    1. 过滤掉所有的空格，接下来如果是数字字符则保存，如果没有则返回0

    2. 判断是否包含 +- 号并标记出来

    3. 判断是否是字符然后再进行计算

    4. 溢出处理 
	
	Refer from to: http://www.cnblogs.com/grandyang/p/4125537.html
	
    引申思考: 从溢出处理和这么多条件的过滤下，可以看得出软件和程序是有工业标准和民用标准的。
    我们要尽量向工业标准靠齐，不断思考和总结。
*/
int myAtoi(char *str) {
    int len = strlen(str);
    int i = 0;
    int flag = 1;
    //flag represent is -1 or 1

    while (i < len && str[i] == ' ') {
        i++;
    }

    if (str[i] == '+' || str[i] == '-') {
        flag = (str[i] == '-') ? -1 : 1;
        i++;
    }

    long int ret = 0;
    while (i < len && str[i] >= '0' && str[i] <= '9') {
        //溢出处理
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)) {

            return (flag == -1) ? INT_MIN : INT_MAX;
        }

        ret = ret * 10 + (str[i++] - '0');

    }

    return ret * flag;
}





//判断是否是字符字符串
bool isNumeric(char c)
{
    if (c < '0' || c > '9')
    {
        return false;
    }
    return true;
}

/*
    "000000000000000000"
    " "
    "+1"
    "-000000000000000000000000000000000000000000000000001"
    "+-2"
    "   +0 123"
    "9223372036854775808"
    "-   234"
    "    -88827   5655  U"
    Meet all the error,it is your method is wrong.

    If you do not think the problem clearly. Do not writing the code.
    And first you should analyze the problem.And point some problem you will meet.And the problem you meet how to deal.
    After the above you think it out.Then go to write it.

    All possible you should think it clearly.And write it on the paper.
*/


// This is my fail code. This is direction of I should change.
int myAtoisTest(char* str)
{
    int i,len;
    long int ret = 0;
    len = strlen(str);
  //  printf("len is %d\n",len);
    bool flag = false,isStart = false;
    int start,count = 0;

    if (len <= 0)
    {
        return 0;
    }

    for (i = 0; i < len; i++)
    {
        //过滤字符串开始的空格
        if (str[i] == ' ')
        {
            if (i == len -1) {
                return 0;
            }
            continue;
        }

        if ((str[i] == '+' || str[i] == '-') && (str[i+1] == '-' || str[i+1] == '+')) {
            return 0;
        }

        if (str[i] == '+') {
            continue;
        }


        // 处理 minus sign
        if (str[i] == '-')
        {
           if (!isNumeric(str[i+1])) {
                    return 0;
            }
            flag = true;
            continue;
        }


        if (isStart && !isNumeric(str[i]))
        {
            break;
        }

        // if str[i] is not numeric,return 0
        if (!isNumeric(str[i]))
        {
            ret = 0;
            return ret;
        }

        //处理字符字符串
        if (isNumeric(str[i]))
        {
            // start init is 0,so start only change once.But you should remember if the true start is 0,it will not change,so you should careful use it.

            if (!isStart)
            {
                if (str[i] == '0') {
                    if (i == len-1) {
                        return 0;
                    }

                    if (!isNumeric(str[i+1])) {
                        return 0;
                    }
                    continue;
                }
                start = i;
                isStart = true;
            }
            count++;
            //printf("%c ",str[i]);
        }

    }

   // printf("start is %d\n",start);
    //printf("count is %d\n",count);

    for (i = start; i < start + count; i++)
    {

        int temp;
        temp = str[i] - '0';

        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > 7)) {
            return flag ? INT_MIN : INT_MAX;
         }

        ret = 10 * ret + temp;


    }

    if (flag)
    {
        ret = ret * -1;
    }

   // printf("ret is %ld\n",ret);
    if (ret > INT_MAX)
    {
        return INT_MAX;
    }
    if (ret < INT_MIN)
    {
        return INT_MIN;
    }

    return ret;

}

int main()
{
    char s[100];
    int ret;
    //ret = calloc(20,sizeof(char));
    while (gets(s))
    {
        printf("s is %s\n",s);
        ret = myAtoi(s);
        printf("%d\n",ret);
    }

    return 0;
}
