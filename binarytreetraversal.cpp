#include<iostream>
using namespace std;

struct node {
    int info;
    node* left;
    node* right;
};

node* nn(int value) {
    node* nn = new node;
    if (nn == nullptr) {
        cout << "Memory not available";
        exit(0);
    }
    nn->info = value;
    nn->left = nullptr;
    nn->right = nullptr;
    return nn;
}

void inorder(node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->info << " ";
    inorder(root->right);
}

void preorder(node* root) {
    if (root == nullptr) return;
    cout << root->info << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->info << " ";
}

int main() {
    node* root = nn(1);
    root->left = nn(2);
    root->right = nn(4);
    root->left->left = nn(8);
    root->left->right = nn(9);
    root->right->left = nn(5);
    root->right->right = nn(1);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
