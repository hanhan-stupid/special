#include <iostream>
#include <string>
using namespace std;
#define MAX 100

struct sqStack
{
    int *m_data;
    int top;
    /* data */
};

void initSqStack(sqStack &sstack)
{
    sstack.m_data = new int[MAX];
    if (sstack.m_data == NULL)
    {
        cout << "the mem is full" << endl;
    }
    else
    {
        sstack.top = 0;
        cout << "init stack is success" << endl;
    }
}
//push function
void pushSqStack(sqStack &sstack, int data)
{
    if (sstack.top >= MAX - 1)
    {
        cout << "the stack is full" << endl;
    }
    else
    {
        
        sstack.m_data[sstack.top] = data;
        cout << "the current top is " << sstack.m_data[sstack.top] << endl;
        sstack.top++;
    }
}
//pop funtion
void popSqStack(sqStack &sstack)
{
    if(sstack.top<=0)
    {
        cout<<"the stack is empty"<<endl;
    }
    else
    {
        int tempData;
        tempData=sstack.m_data[sstack.top-1];
        cout<<"the data poped is "<<tempData<<endl;
        sstack.top--;
        cout << "the current top is " << sstack.m_data[sstack.top-1] << endl;
    }
}
//
void peekStack(sqStack sstack)
{
    int data;
    data=sstack.m_data[sstack.top-1];
    cout<<"the top of data is "<<data<<endl;
}
//test
void test()
{
    sqStack mysstack;
    initSqStack(mysstack);
    int num;
    cout << "pls input the num of data" << endl;
    cin >> num;
    int data;
    for (int i = 0; i < num; i++)
    {
        
        cout << "pls input the data to be pushed" << endl;
        cin >> data;
        pushSqStack(mysstack, data);
    }
    peekStack(mysstack);
    

}
int main(void)
{
    test();
}