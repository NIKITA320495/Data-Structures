#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};
node *root=nullptr;
node *newnode(int val)
{
    node *nn=new node;
    nn->info=val;
    nn->left=nullptr;
    nn->right=nullptr;
}
void *build123()
{
    root=newnode(2);
    root->left=newnode(1);
    root->right=newnode(3);
    cout<<(root->left)->info<<root->info<<(root->right)->info;
}
void mirror(node*p)
{
    if(p==nullptr)
    {
        return ;
    }
    else
    {
        node *temp;
        mirror(p->left);
        mirror(p->right);
        temp=p->left;
        p->left=p->right;
        p->right=temp;
}
}
int main()
{
build123();
mirror(root);
cout<<endl<<(root->left)->info<<root->info<<(root->right)->info;
}
