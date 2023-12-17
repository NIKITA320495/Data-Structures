#include<iostream>
#include<queue>
using namespace std;

struct node {
    node *left;
    node *right;
    int info;
};

node *newnode(int info) {
    node *nn = new node;
    nn->info = info;
    nn->left = nullptr;
    nn->right = nullptr;
    return nn;
}

void rightview(node *root) {
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            node *currentNode = q.front();
            q.pop();

            // Print the rightmost element in each level
            if (i == n - 1) {
                cout << currentNode->info << " ";
            }

            // Add left and right children to the queue
            if (currentNode->left != nullptr)
                q.push(currentNode->left);
            if (currentNode->right != nullptr)
                q.push(currentNode->right);
        }

        // Add a newline to separate levels
        cout << endl;
    }
}

int main() {
    node *root;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    cout << "Right View: ";
    rightview(root);

    return 0;
}
