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
    nn->info=info;
    nn->left=nullptr;
    nn->right=nullptr;
    return nn;
}
node* checktarget(node* root, int target) {
    if (root != nullptr) {
        if (root->info == target) {
            return root;
        }

        // Check the left subtree and return if found
        node* leftResult = checktarget(root->left, target);
        if (leftResult != nullptr) {
            return leftResult;
        }

        // Check the right subtree and return if found
        node* rightResult = checktarget(root->right, target);
        if (rightResult != nullptr) {
            return rightResult;
        }
    }

    // Return nullptr if the target is not found in the current subtree
    return nullptr;
}

void nodesatk(node *root , int target ,int k)
{ int dis;
node *r=checktarget(root,target);
if(r!=nullptr)
{   if(dis==0)
    {
                cout<<r->info;
    }
    dis=k-1;
    nodesatk(r->left,target,dis);
    nodesatk(r->right,target,dis);
        }

}

int main()
{
    node *root;
    root=newnode(1);
    root->right=newnode(2);
    root->left=newnode(5);
    (root->left)->left=newnode(6);
    (root->left)->left->right=newnode(7);
    (root->right)->left=newnode(3);
    (root->right)->right=newnode(4);
    nodesatk(root,5,2);
}

