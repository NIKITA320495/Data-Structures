#include<iostream>
#include<climits>
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
int maxPathSum(node *root) {
    if (root == nullptr) {
        return INT_MIN; // Return a very small value for an empty tree
    }

    // Calculate the maximum path sum for the left and right subtrees
    int leftMax = maxPathSum(root->left);
    int rightMax = maxPathSum(root->right);

    // Find the maximum sum among the left, right, and current root values
    int currentMax = max(root->info, max(leftMax + root->info, rightMax + root->info));

    // Print the maximum sum when a leaf node is encountered
    if (root->left == nullptr && root->right == nullptr) {
       return currentMax;
    }

    return currentMax;
}
int main()
{
    node *root=nullptr;
    root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(6);
    root->left->right=newnode(5);
    root->right->left=newnode(-2);
    root->right->right=newnode(1);
    int sum=maxPathSum(root);
    cout<<sum;
}
