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
    //cout<<(root->left)->info<<root->info<<(root->right)->info;
}
void printarray(int ints[],int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        cout<<ints[i];
    }
}
void printpathrec(node *p,int path[],int plen)
{
    if (p==nullptr)
        return ;
    path[plen]=p->info;
    plen++;
    if((p->left==nullptr) &&(p->right==nullptr))
        printarray(path,plen);
    else
    {
        printpathrec(p->left,path,plen);
        printpathrec(p->right,path,plen);
    }
}
void printpath(node *p)
{
    int path[100];
    printpathrec(p,path,0);
}


int main()
{
    root=build123();
    printpath(root);
}
