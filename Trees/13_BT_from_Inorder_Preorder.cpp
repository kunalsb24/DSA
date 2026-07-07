#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int x) {
        key = x;
        left = right = NULL;
    }
};

// Method 1: Time:O(n^2), Space: O(h)
// int preIndex = 0;

// Node* buildTree(int in[], int pre[], int is, int ie) {
//     if (is > ie)
//         return NULL;

//     Node* root = new Node(pre[preIndex++]);

//     int inIndex;
//     for (inIndex = is; inIndex <= ie; inIndex++) {
//         if (in[inIndex] == root->key)
//             break;
//     }

//     root->left = buildTree(in, pre, is, inIndex - 1);
//     root->right = buildTree(in, pre, inIndex + 1, ie);

//     return root;
// }

// void inorder(Node* root) {
//     if (root == NULL)
//         return;

//     inorder(root->left);
//     cout << root->key << " ";
//     inorder(root->right);
// }

// Method 2: Hashing 
// Time:O(n), Space: O(h)


    int preIndex = 0;
    unordered_map<int, int> mp;
    Node* buildTree(int in[], int pre[], int is, int ie) {
    if (is > ie)
        return NULL;

    Node* root = new Node(pre[preIndex++]);

    int inIndex = mp[root->key];

    root->left = buildTree(in, pre, is, inIndex - 1);
    root->right = buildTree(in, pre, inIndex + 1, ie);

    return root;
   }

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}


int main() {
    int in[] = {40, 20, 50, 10, 30};
    int pre[] = {10, 20, 40, 50, 30};

    int n = sizeof(in) / sizeof(in[0]);

    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    Node* root = buildTree(in, pre, 0, n - 1);

    inorder(root);
}