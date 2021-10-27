#include<iostream>
#include<string>
using namespace std;
struct student
{
    string name;
    int id;
};

void stdIoTest()
{
    int num = 3; //人数
    student stu[num];
    cout<<"Enter the student's name and student numbers."<<endl;
    for(int i = 0;i<num;i++)
    {
        cin>>stu[i].name>>stu[i].id;
    }
    //show
    for(int i = 0;i<num;i++)
    {
        cout<<stu[i].name<<"    "<<stu[i].id<<endl;
    }
}
int main(void)
{
    stdIoTest();
    system("pause");
}