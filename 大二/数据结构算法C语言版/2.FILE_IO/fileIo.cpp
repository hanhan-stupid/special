#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct student
{
    string name;
    int id;
};

void creat(int num)
{
    fstream ofs;
    ofs.open("class2001.txt",ios::out);
    if(!ofs.is_open())
        cout<<"file fail "<<endl;
        student stu[num];
    ofs<<"name"<<"   "<<"id"<<endl;
    for(int i =0;i<num;i++)
    {
        cin>>stu[i].name>>stu[i].id;
        ofs<<stu[i].name<<"      "<<stu[i].id<<endl;
    }
    ofs.close();
}
void show(int num)
{
    fstream ifs;
    ifs.open("class2001.txt",ios::in);
    if(!ifs.is_open())
        cout<<"file fail "<<endl;
    student stu[num];
    while(!ifs.eof())
    {
        ifs>>stu[0].name>>stu[0].name       //移除”name “和 ”id“
        >>stu[0].name>>stu[0].id
        >>stu[1].name>>stu[1].id
        >>stu[2].name>>stu[2].id;
    }
    cout<<"name"<<"  "<<"id"<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<stu[i].name<<"   "<<stu[i].id<<endl;
    }
    ifs.close();
}
int main(void)
{
    int num = 3;
    creat(num);
    show(num);
    system("pause");
}