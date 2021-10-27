#include <iostream>
using namespace std;

int main(void)
{
    int ge, shi, bai, qian, num = 0;
    for (int i = 1; i <= 2020; i++)
    {
        ge = i % 10;
        shi = i / 10 % 10;
        bai = i / 100 % 10;
        qian = i / 1000 % 10;
        if (ge == 2)
            num++;
        if (shi == 2)
            num++;
        if (bai == 2)
            num++;
        if (qian == 2)
            num++;
    }
    cout<<num<<endl;
}

//624