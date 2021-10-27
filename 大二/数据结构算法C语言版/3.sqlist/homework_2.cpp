#include<iostream>
#include<string>
#include<fstream>
#define MAX 100
using namespace std;

struct Student
{
    /* data */
    string m_major;
    string m_className;
    string m_studentName;
};
struct classList
{
    /* data */
    Student *m_classData;
    int length;
};

int initList(classList &List)
{
    List.m_classData=new Student[MAX];
    if(!List.m_classData)
    {
        cout<<"the memory is full"<<endl;
        return 0;
    }
    List.length=0;
    return 1;
}

int readTable(classList &List,string fileName)
{
    fstream ifs;
    ifs.open(fileName,ios::in);
    if(!ifs)
    {
        cout<<"file open fail"<<endl;
        return 0;
    }
    while(!ifs.eof())
    {
        ifs>>List.m_classData[List.length].m_major>>List.m_classData[List.length].m_className>>List.m_classData[List.length].m_studentName;
        List.length++;
    }
    cout<<"the table is inputed"<<endl;
    cout<<"the current length of list is "<<List.length<<endl;
    ifs.close();
}

void show(classList list)
{
    for(int i=0;i<list.length;i++)
    {
        cout<<list.m_classData[i].m_major<<"   "<<list.m_classData[i].m_className<<"   "<<list.m_classData[i].m_studentName<<"   "<<endl;       
    }
}

void test()
{
    classList List;
    initList(List);
    readTable(List,"D:\\Program Files (x86)\\VScode_Project\\Class\\class.txt");
    show(List);
}
//locate
int Locate(classList List,string name)
{
    for(int i=0;i<List.length;i++)
    {
        if(List.m_classData[i].m_studentName==name)
            return i;
            
    }
    cout<<"the name is not in the class"<<endl;
    return -1;
}
//insert
int insert(classList &list,int i,Student data)
{
    if(i<1||i>list.length)
    {
        cout<<"the pos tobe insert is out of list"<<endl;
        return 0;
    }
    if(list.length==MAX)
    {
        cout<<"the list is full"<<endl;
        return 0;
    }
    for(int j=list.length;j>=i;j--)
    {
        list.m_classData[j+1]=list.m_classData[j];
    }
    list.m_classData[i].m_className=data.m_className;
    list.m_classData[i].m_major=data.m_major;
    list.m_classData[i].m_studentName=data.m_studentName;
}
//del
int Del(classList &list, int pos)
{
     if(pos<1||pos>list.length)
    {
        cout<<"the pos tobe insert is out of list"<<endl;
        return 0;
    }
    for(int i=pos;i<list.length;i++)
    {
        list.m_classData[i]=list.m_classData[i+1];
    }
    list.length--;

}
void test01()
{
    classList List;
    initList(List);
    readTable(List,"D:\\Program Files (x86)\\VScode_Project\\Class\\class.txt");
    int i=Locate(List,"Ôøº­º­");
    cout<<i<<endl;
}
void homeWork()
{
    cout<<"*****1.³õÊ¼»¯Ë³Ðò±í*****"<<endl;
    cout<<"*****2.½¨Á¢Ë³Ðò±í*****"<<endl;
    cout<<"*****3.Ë³Ðò±í²éÕÒ*****"<<endl;
    cout<<"*****4.Ë³Ðò±í²åÈë*****"<<endl;
    cout<<"*****5.Ë³Ðò±íÉ¾³ý*****"<<endl;
    cout<<"*****6.Ë³Ðò±íÏÔÊ¾*****"<<endl;
    cout<<"*****0.³ÌÐòÍË³ö*****"<<endl;
    cout<<"pls input your choose"<<endl;
    int i;
    cin>>i;
    string name;
    int pos;
    string confirm;
    Student data;
    switch (i)
    {
        case 1:       
            classList List;
            initList(List);
            cout<<"list creat succes"<<endl;
        /* code */

        break;
        case 2:
            readTable(List,"D:\\Program Files (x86)\\VScode_Project\\Class\\class.txt");
        /* code */
        break;
        case 3:
            cout<<"pls input the name and to be find"<<endl;
            cin>>name;
            pos=Locate(List,name);
            cout<<"the student is "<<List.m_classData[pos].m_major<<"   "<<List.m_classData[pos].m_className<<"   "<<List.m_classData[pos].m_studentName<<"   "<<endl;   
        /* code */
        break;
        case 4:
            cout<<"pls input the data to be inserted"<<endl;
            cin>>data.m_className>>data.m_major>>data.m_studentName;
            cout<<"pls input the position to be inserted"<<endl;
            cin>>pos;
            insert(List,pos,data);
        /* code */
        break;
        case 5:
        cout<<"pls input del's pos"<<endl;
            cin>>pos;
            cout<<"Whether or not to delete the stu"<<List.m_classData[pos].m_studentName<<"confirm input y,els input n"<<endl;
            cin>>confirm;
            if(confirm=="y")
            Del(List,pos);

        /* code */
        break;
        case 6:
        /* code */
            show(List);
        break;
        case 0:     exit(0);
        /* code */
        break;
    
    default:
        break;
    }
}
int main(void)
{
    while(1)
    homeWork();
    
}