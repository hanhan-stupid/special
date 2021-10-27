#include<iostream>
using namespace std;

int zeroes(int n)
{
    int r;
    while(n >= 5)
        n = n / 5;
        r+=n;
        return r;
}
int main(void)
{
    int n,r;
    cin>>n;
    r=zeroes(n);
    cout<<r<<endl;
}