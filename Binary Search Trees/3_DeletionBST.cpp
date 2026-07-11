#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

// Find the smallest node in a subtree
Node* getSuccessor(Node *curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Delete a node from BST
Node* delNode(Node *root, int x) {

    if (root == NULL)
        return root;

    if (x < root->key)
        root->left = delNode(root->left, x);

    else if (x > root->key)
        root->right = delNode(root->right, x);

    else {
        // Case 1: No left child
        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else {
            Node *succ = getSuccessor(root);

            root->key = succ->key;

            root->right = delNode(root->right, succ->key);
        }
    }

    return root;
}

// Inorder Traversal
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    cout<<"Before Deletion: ";
    inorder(root);
    cout << endl;
    root = delNode(root, 50);

    
    cout<<"After Deletion: ";
    inorder(root);

    return 0;
}