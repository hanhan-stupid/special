#include <iostream>
#include <string>
using namespace std;
//define the empty linklist
struct linkNode
{
    /* data */
    string m_data;
    linkNode *m_next;
};
//define the init function of linnklist
int init(linkNode *&linkList)
{
    linkList->m_next = NULL;
    return 1;
}
//define function of creat list
int creatList(linkNode *&linkList)
{
    int num;
    cout << "pls input the num of node" << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "pls input the node data" << endl;
        string data;
        cin >> data;
        linkNode *temp = new linkNode();
        temp->m_data = data;
        temp->m_next = linkList->m_next;
        linkList->m_next = temp;
    }
    return 1;
}
void showlist(linkNode *linklist)
{
    linkNode *pointer = new linkNode();
    pointer->m_next = NULL;

    pointer->m_next = linklist->m_next;
    while (pointer != NULL)
    {
        cout << pointer->m_data << endl;
        pointer = pointer->m_next;
    }
}
void findNodeByvalue(linkNode *linkList, string data)
{
    linkNode *pointer = new linkNode();
    pointer = linkList->m_next;
    int i = 1;
    while (pointer != NULL && pointer->m_data != data)
    {
        pointer = pointer->m_next;
        i++;
    }
    if (pointer != NULL)
    {
        cout << "the node is found is " << i << endl;
    }
    else
        cout << "fing fail" << endl;
}
//delete
void deleteNode(linkNode *&linkList, int pos)
{
    linkNode* pointer=new linkNode();
    pointer=linkList;
    int i=0;
    while(i<pos-1&&pointer!=NULL)
    {
        pointer=pointer->m_next;
        i++;
    }
    if(pointer==NULL||i>pos-1)
    cout<<"delete fail"<<endl;
    else
    {
        linkNode* temp=new linkNode();
        temp=pointer->m_next;
        pointer->m_next=temp->m_next;
        delete temp;
        cout<<"delete success"<<endl;
    }
}
void insertNode(linkNode *&linkList,int pos,string data)
{
    linkNode* pointer=new linkNode();
    pointer=linkList;
    int i=0;
    while(i<pos-1&&pointer!=NULL)
    {
        pointer=pointer->m_next;
        i++;
    }
    if(pointer==NULL||i>pos)
    cout<<"insert dail"<<endl;
    else
    {
        linkNode *temp=new linkNode();
        temp->m_data=data;
        temp->m_next=pointer->m_next;
        pointer->m_next=temp;
    }
}

void test()
{
    //creat a empty linklist
    linkNode *mylist = new linkNode();
    init(mylist);

    //creat first node
    linkNode *stu1 = new linkNode();
    stu1->m_data = "Z1";
    stu1->m_next = NULL;

    //creat second node
    linkNode *stu2 = new linkNode();
    stu2->m_data = "Z2";
    stu2->m_next = NULL;

    //creat list
    stu1->m_next = stu2;
    mylist->m_next = stu1;

    //creat node 3
    linkNode *stu3 = new linkNode();
    stu3->m_data = "Z3";
    stu3->m_next = NULL;
    //首插
    stu3->m_next = mylist->m_next;
    mylist->m_next = stu3;

    showlist(mylist);
}
void test2()
{
    //creat a empty linklist
    linkNode *mylist = new linkNode();
    init(mylist);
    creatList(mylist);
    showlist(mylist);
    string data;
    cout << "pls input the value of node" << endl;
    cin >> data;
    findNodeByvalue(mylist, data);
    showlist(mylist);
}

void test3()
{
    //creat a empty linklist
    linkNode *mylist = new linkNode();
    init(mylist);
    creatList(mylist);
    showlist(mylist);
    int pos;
    cout << "pls input the position" << endl;
    cin >> pos;
    string data;
    cout<<"input data"<<endl;
    cin>>data;
    insertNode(mylist, pos, data);
    showlist(mylist);
}
int main(void)
{
    test3();
}