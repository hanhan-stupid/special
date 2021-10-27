#include<iostream>
using namespace std;
#define max 5

struct sqlist
{
    int * m_Data;
    int m_Lenth;/* data */
};


int inintSqlist(sqlist &mySqlist)
{
    mySqlist.m_Data=new int[max];
    if(mySqlist.m_Data==NULL)
    {
        cout<<"creat fail"<<endl;
        return 0;      
    }
    mySqlist.m_Lenth=0;
    for(int i=0;i<max;i++)
    {
        cout<<"pls input "<<i<<"data"<<endl;
        cin>>mySqlist.m_Data[i];
        mySqlist.m_Lenth++;
    }
}

void showList(sqlist list)
{
    for(int i=0;i<list.m_Lenth;i++)
    cout<<list.m_Data[i];
}

//define the function of locate
int locateSq(sqlist sList,int newData)
{
    int i=0;
    while (i<sList.m_Lenth&&sList.m_Data[i]!=newData)
    {
        /* code */
        i++;
    }
    if(i<sList.m_Lenth&&sList.m_Data[i]==newData)
        return i;
    else
        return -1;
}

int updataSq(sqlist &sList,int oldData,int newData)
{
    int pos;
    pos=locateSq(sList,oldData);
    if(pos==-1)
    {   cout<<"the data is not in the sqList"<<endl;
        return 0;
    }
    sList.m_Data[pos]=newData;
    return 1;
}
//define the funtion of insert
int insertSq(sqlist &slist,int i,int newData)
{
    if (i<0||i>slist.m_Lenth-1)
    {
        cout<<"the postion i is not inthe list"<<endl;/* code */
        return 0;
    }
    for(int k=slist.m_Data[slist.m_Lenth-1];k>=i;k--)
    {
        slist.m_Data[i+1]=slist.m_Data[i];
    }    
    slist.m_Data[i]=newData;
    slist.m_Lenth++;
    return 1;
}

//define the funtion of delate
int delateSq(sqlist &sList,int i)
{
    if (i<0||i>sList.m_Lenth-1)
    {
        cout<<"the postion i is not inthe list"<<endl;/* code */
        return -1;
    }
    int dData;
    dData=sList.m_Data[i];
   
    for(int k=i;k<sList.m_Lenth-1;k++)
    {
        sList.m_Data[k]=sList.m_Data[k+1];
    } 
    sList.m_Lenth-=1;
    return dData;
}

void test04()
{
    sqlist mylisst;
    inintSqlist(mylisst);
    cout<<"pls input the pos and data to be insert"<<endl;
    int i;
    cin>>i;
    delateSq(mylisst,i);
    showList(mylisst);
}
void test03()
{
    sqlist mylisst;
    inintSqlist(mylisst);
    cout<<"pls input the pos and data to be insert"<<endl;
    int i,nData;
    cin>>i>>nData;
    insertSq(mylisst,i,nData);
    showList(mylisst);
}
void test02()
{
    sqlist mylisst;
    inintSqlist(mylisst);
    int oData,nData;
    cout<<"pls input the old data and new data";
    cin>>oData>>nData;
    updataSq(mylisst,oData,nData);
    showList(mylisst);
}
void test01()
{
    sqlist myList;
    inintSqlist(myList);
    int data;
    cout<<"pls input the data to be loccated"<<endl;
    cin>>data;
}


int main(void)
{
    test04();
    system("pause");
}

