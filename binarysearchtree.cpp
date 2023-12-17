#include<iostream>
using namespace std;

struct node
{
    node *left;
    int info;
    node *right;
};

node *newnode(int info)
{
    node *nn = new node;
    nn->info = info;
    nn->left = nullptr;
    nn->right = nullptr;
    return nn;
}

node *insertnode(node *root, int val)
{
    if (root == nullptr)
        return newnode(val);
    if (val < root->info)
        root->left = insertnode(root->left, val);
    else
        root->right = insertnode(root->right, val);
    return root;
}

node *deletenode(node *p, int key)
{
    if (p == nullptr)
        return nullptr; // Key not found

    node *temp;

    if (p->info == key)
    {
        if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }
        else if (p->left == nullptr && p->right != nullptr)
        {
            temp = p->right;
            delete p;
            return temp;
        }
        else if (p->left != nullptr && p->right == nullptr)
        {
            temp = p->left;
            delete p;
            return temp;
        }
        else
        {
            temp = p->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            p->info = temp->info;
            p->right = deletenode(p->right, temp->info); // Continue with deletion in the right subtree
            return p;
        }
    }

    p->left = deletenode(p->left, key);
    p->right = deletenode(p->right, key);

    return p;
}

int treemin(node *root)
{
    node *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current->info;
}

void inorder(node *p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
}

int main()
{
    cout << "\t\t\t\tBINARY SEARCH TREE" << endl;
    cout << "\t\t\t\t1. INSERT NODE" << endl;
    cout << "\t\t\t\t2. DELETE NODE" << endl;
    cout << "\t\t\t\t3. FIND MINIMUM NODE" << endl;
    cout << "\t\t\t\t4. PRINT DATA IN INCREASING ORDER" << endl;
    cout << "\t\t\t\t5. EXIT" << endl;

    int choice, x, minval;
    int key;
    node *root = nullptr;
    char ch;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Enter value: ";
                cin >> x;
                root = insertnode(root, x);
                cout << "Do you want to enter more values? (y/n): ";
                cin >> ch;
            } while (ch == 'y');
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> key;
            root = deletenode(root, key);
            break;
        case 3:
            minval = treemin(root);
            cout << "Minimum value: " << minval << endl;
            break;
        case 4:
            cout << "Inorder traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Exit" << endl;
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
        cout << "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
