#include<iostream>
using namespace std;
struct node
{
    node *left;
    int info;
    node *right;
};
node *newnode (int info)
{
    node *nn=new node;
    nn->info=info;
    nn->left=nullptr;
    nn->right=nullptr;
}
int treemin(node *root)
{
    node *current = root;
    while(current->left!=nullptr)
    {
        current=current->left;
        return (current->info);
    }
}
int treemax(node *root)
{
  node *current = root;
    while(current->right!=nullptr)
    {
        current=current->right;
        return (current->info);
    }
}
bool isbst(node *p)
{
    if(p==nullptr)
    {
        return true;
    }
    if(p->left!=nullptr && treemin(p->left)>p->info)
        return false;
    if(p->right!=nullptr &&treemax(p->right)<p->info)
        return false;
    return true;
}
int main()
{
    node *root=nullptr;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    bool val=isbst(root);
    cout<<val;
}
