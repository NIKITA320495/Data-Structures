#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};
node *root1=nullptr;
node *root2=nullptr;
node *newnode(int val)
{
    node *nn=new node;
    nn->info=val;
    nn->left=nullptr;
    nn->right=nullptr;
}
node *build123()
{
    root1=newnode(2);
    root1->left=newnode(1);
    root1->right=newnode(3);
    return root1;
}
node *buildb123()
{
    root2=newnode(8);
    root2->left=newnode(1);
    root2->right=newnode(3);
    return root2;
}
bool same(node *a,node *b)
{
    if((a==nullptr)&&(b==nullptr))
    {
        return true;
    }
    else if((a!=nullptr)&&(b!=nullptr))
    {
        return(a->info==b->info)&&same(a->left,b->left)&&same(a->right,b->right);
    }
    else
    {
        return false;
    }
}
int main()
{
    root1=build123();
    root2=buildb123();
    bool val=same(root1,root2);
    cout<<val;
}
