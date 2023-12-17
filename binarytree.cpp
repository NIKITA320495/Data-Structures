#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
};
node *newnode (int info)
{
    node *nn=new node;
    nn->info=info;
    nn->left=nullptr;
    nn->right=nullptr;
}
node* insert(node* root, int key, char direction) {
    if (root == nullptr) {
        return newnode(key);
    }
    if(direction=='l')
    {
        root->left= insert(root->left,key,direction);
    }
    else if(direction=='r')
    {
        root->right=insert(root->right,key,direction);

    }
    else
    {
        cout<<"invalid";
    }
    return root;
}
void inorder(node *p)
{
    if(p!=nullptr)
    {
        inorder(p->left);
        cout<< p->info;
        inorder(p->right);
    }
}
void preorder(node *p)
{
    if(p!=nullptr)
    {
        cout<<p->info;
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p)
{
    if(p!=nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->info;
    }
}
node * deletenode(node *p,int key)
{
      if (p == nullptr) {
        return nullptr; // Key not found
    }
    node *temp;
    if(p->info==key)
    {
        if(p->left==nullptr && p->right==nullptr)
        {
            temp=p;
            free(p);
            return (temp);
        }
        else if(p->left==nullptr && p->right!=nullptr)
        {
            temp=p;
            p=p->right;
            free(temp);
            return(p);
        }
        else if(p->left!=nullptr && p->right == nullptr)
        {
            temp=p;
            p=p->left;
            free(temp);;
            return p;
        }
        else
        {
            temp=p->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            p->info = temp->info;
            p->right = deletenode(p->right, temp->info); // Continue with deletion in the right subtree
            return p;
        }
    }
    p->left=deletenode(p->left,key);
    p->right=deletenode(p->right,key);
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
    cout<<"\t\t\t\tBINARY TREE"<<endl;
    cout<<"\t\t\t\t1.INSERTION"<<endl;
    cout<<"\t\t\t\t2.DELETION"<<endl;
    cout<<"\t\t\t\t3.PREORDER ,INORDER AND POSTORDER TRAVERSAL"<<endl;
    cout<<"\t\t\t\t4.CHECK FOR BINARY SEARCH TREE"<<endl;
    cout<<"\t\t\t\t5.EXIT"<<endl;
    int choice;
    int x;
    int val;
    char ch,direction;
    do
    {
        cout<<"Enter your choice";
        cin>>choice;
        switch (choice)
        {
            case 1:cout<<"Enter the value of root";
                    cin>>x;
                    root=newnode(x);
                    do
                    {
                        cout<<"Do you want to enter a value(enter -1 for nullvalue)";
                        cin>>ch;
                        if(ch=='y')
                        {
                            cout<<"Enter value";
                            cin>>val;
                            if(val!=-1)
                            {
                                   cout<<"Enter direction";
                                   cin>>direction;
                                   root=insert(root,val,direction);
                            }
                            else{
                                cout<<"inserting nullptr";
                            }

                        }

                    }while(ch=='y');
                    break;
            case 2:
                int x;
                cout<<"enter the value to delete";
                cin>>x;
                deletenode(root,x);
                break;
            case 3: cout<<"inorder traversal:";
                    inorder(root);
                    cout<<endl;
                    cout<<"preorder traversal:";
                    preorder(root);
                    cout<<endl;
                    cout<<"postorder traversal:";
                    postorder(root);
                    cout<<endl;
                    break;
            case 4:bool val;
                val=isbst(root);
                cout<<val;
                break;
            case 5:
                cout<<"wrong choice";
                break;
            default:
                cout<<"invalid choice";
        }
        cout<<"Do you want to continue";
        cin>>ch;
    }while(ch=='y');
}
