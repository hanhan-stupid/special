#include <iostream>
#include <string>
using namespace std;
//
struct linkStackNode
{
    string m_data;
    linkStackNode *m_next;
    /* data */
};
//init function
void initLinkStack(linkStackNode *&linkStack)
{
    linkStack->m_next = NULL;
    cout << "the init operation success" << endl;
}
//push
void pushLinkStack(linkStackNode *&linkstack, string data)
{
    linkStackNode *pointer = new linkStackNode();
    pointer = linkstack->m_next;
    linkStackNode *tempNode = new linkStackNode();
    tempNode->m_data = data;
    tempNode->m_next = pointer;
    linkstack->m_next = tempNode;
    cout << "the current top is " << linkstack->m_next->m_data << endl;
}
//pop
void popLinkStack(linkStackNode *&linkStack)
{
    string data;
    data = linkStack->m_next->m_data;
    cout << "the poped data is " << data<<endl;
    linkStack=linkStack->m_next;
    cout<<"the data is "<<linkStack->m_next->m_data<<endl;
}

//test
void test()
{
    linkStackNode *mylinkstack = new linkStackNode();
    initLinkStack(mylinkstack);
    int num;
    cout << "input the num of data" << endl;
    cin >> num;
    string data;
    for (int i = 0; i < num; i++)
    {
        cin >> data;
        pushLinkStack(mylinkstack, data);
    }
    popLinkStack(mylinkstack);
}
int main(void)
{
    test();
}
