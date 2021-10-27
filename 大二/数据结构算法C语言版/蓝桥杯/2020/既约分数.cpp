/*如果一个分数的分子和分母的最大公约数是1，这个分数称为既约分数。
例如，3/4,5/2,1/8,7/1都是既约分数。
请问，有多少个既约分数，分子和分母都是1到2020之间的整数（包括1和2020）*/

#include <iostream>
using namespace std;
int greatest(int x, int y)
{
    for (int i = min(x, y); i > 0; i--)
    {
        if (x % i == 0 && y % i == 0)
        {
            return i;
        }
    }
}

int main(void)
{
    int num = 0;
    for (int i = 0; i < 2021; i++)
        for (int j = 0; j < 2021; j++)
        {
            if (greatest(i, j) == 1)
            {
                num++;
            }
        }
    cout<<num;
}

//2481215