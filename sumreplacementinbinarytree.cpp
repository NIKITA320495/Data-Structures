#include<iostream>
using namespace std;
struct node
{
    node *left;
    node *right;
    int info;
};
node *newnode(int info)
{
    node *nn=new node;
    nn->info=info;
    nn->left=nullptr;
    nn->right=nullptr;
    return nn;
}
void inorder(node *root)
{
    if(root!=nullptr)
    {
        inorder(root->left);
        cout<<root->info;
        inorder(root->right);
    }
}
int sumreplacement(node *root)
{
  if(root==nullptr)
  {
      return 0;
  }
  else
  {
      root->info=root->info+sumreplacement(root->left)+sumreplacement(root->right);
  }
  return root->info;
}
int main()
{
    node *root;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(9);
    root->right->right=newnode(3);
    inorder(root);
    cout<<endl;
    int sum=sumreplacement(root);
    cout<<sum;
    cout<<endl;
    inorder(root);
}
