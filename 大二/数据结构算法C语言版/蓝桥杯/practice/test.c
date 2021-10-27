#include<stdio.h>
int main()
{
    int  i;//钱
    int  d=0;//日子
    int  sum=0;//总钱数
    for(i=0;sum<108;i++){
        d++;
        sum +=i;
        printf("第%d天总%d元\n",d,sum); //本行仅测试用，可删
        i=i+2;
    }
    printf("%d",d);//第多少天成功
    return  0;
}