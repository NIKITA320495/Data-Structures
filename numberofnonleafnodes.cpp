#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};
node *newnode(int value)
{
    node *nn=new node;
    nn->info=value;
    nn->left=nullptr;
    nn->right=nullptr;
    return nn;
}
node *root=nullptr;
node *build123()
{

    root=newnode(2);
    root->right=newnode(3);
    root->left=newnode(1);
    (root->left)->left=newnode(5);
    (root->left)->right=newnode(8);
    ((root->left)->right)->left=newnode(9);
    (root->right)->left=newnode(7);
    (root->right)->right=newnode(9);
    (root->left->left)->left=newnode(10);
    (root->left->left)->right=newnode(11);

    return root;
}
int countnonleaf( node *p)
{
    if(p==nullptr)
        return 0;
    else if((p->left==nullptr)&&(p->right==nullptr))
        return 0;
    else
        return(countnonleaf(p->left)+countnonleaf(p->right)+1);
}
int main()
{
    root=build123();
    int countnl=countnonleaf(root);
    cout<<countnl;
}

