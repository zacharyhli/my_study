#include <stdio.h>

//计算一个值中值为1的位的个数:最终版本
int count_one_bits(unsigned value)  //这个函数返回参数值中值为1的位的个数
{
    int ones;
    for(ones = 0; value != 0; value >>= 1)   //当这个值还有一些值为1的位时
    {
        if(value & 1 != 0)  //如果最低位的值为1，计数增1
            ones += 1;
    }

    return ones;
}

int main(int argc, char const* argv[])
{
    int tmp = 0;
    int counter = 0;

    printf("请输入一个数来测试其二进制中1的位的个数: ");
    scanf("%d", &tmp);
    counter = count_one_bits(tmp);
    printf("该值中值为1的位的个数为: %d\n", counter);

    return 0;
}
