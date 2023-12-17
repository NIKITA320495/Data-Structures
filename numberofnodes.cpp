#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};
 node *newnode(int info)
{
    node *nn=new node;
    if(nn==nullptr)
    {
        cout<<"memory not available";
        exit(0);
    }
    nn->info=info;
    nn->left=nullptr;
    nn->right=nullptr;
    return nn;
}
node *root=nullptr;
 node *build123()
 {

     root=newnode(2);
     root->left=newnode(1);
     root->right=newnode(3);
     return root;
 }
 int countnode(node *root)
 {
     if(root==nullptr)
     {
         return 0;

     }
     else
     {
         return countnode(root->left)+1+countnode(root->right);
     }
 }
 int main()
 {
     int count;
   root=build123();
   count=countnode(root);
   cout<<count;
}
