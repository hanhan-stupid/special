#include <iostream>
#include<string>
using namespace std;

struct TreeNode
{
    string val;
    TreeNode* left;
    TreeNode* right;
};
void init(TreeNode *& tree)
{
    tree->left=NULL;
    tree->right=NULL;
}
void creatNode(TreeNode*& tree)
{
    TreeNode *node=new TreeNode();
    
}
int main(void)
{

}