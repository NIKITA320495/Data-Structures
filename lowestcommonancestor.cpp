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
int *printarray(int ints[],int len)
{
    int i;
    int *arr=new int[len];
    for(i=0;i<len;i++)
    {
       arr[i]=ints[i];
    }
    return arr;
}
int* printpathrec(node *p,int path[],int plen,int key)
{
    if (p==nullptr)
        return nullptr ;
    path[plen]=p->info;
    plen++;
    if(p->info==key)
        return printarray(path,plen);
    else
    {
        int* leftResult = printpathrec(p->left, path, plen, key);
        int* rightResult = printpathrec(p->right, path, plen, key);

        // Check if the key is found in the left or right subtree
        if (leftResult != nullptr)
            return leftResult;
        else if (rightResult != nullptr)
            return rightResult;
        else
            return nullptr;
    }
}

int * printpath(node *p,int key)
{
    int path[100];
    return printpathrec(p,path,0,key);
}
void lca(node *root,int n1,int n2)
{

    int path1[100], path2[100];
    int len1 = 0, len2 = 0;
   int *result1=printpathrec(root,path1,len1,n1);
   int *result2=printpathrec(root,path2,len2,n2);
    int i = 0;
    if (result1 != nullptr && result2 != nullptr)
    {
    while (result1[i] != '\0' && result2[i] != '\0' && result1[i]==result2[i])
    {
        i++;
    }
 cout << "Lowest Common Ancestor: " << result1[i - 1] << endl;
        delete[] result1; // Don't forget to free the allocated memory
        delete[] result2;
    }
}
int main()
{
    node *root;
    root=newnode(2);
    root->right=newnode(3);
    root->left=newnode(1);
    (root->left)->left=newnode(5);
    (root->left)->right=newnode(8);
    (root->right)->left=newnode(7);
    (root->right)->right=newnode(9);
    (root->left->left)->left=newnode(10);
    //lca(root,5,8);
     int *ans = printpath(root, 5);

    // Check if the path exists
    if (ans != nullptr)
    {
        // Print the elements of the array
        for (int i = 0; ans[i] != '\0'; i++)
        {
            cout << ans[i] << " ";
        }
        // Don't forget to free the allocated memory
        delete[] ans;
    }
    else
    {
        cout << "Path not found for the given key." << endl;
    }
    lca(root,5,7);

}
