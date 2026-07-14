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

Node *Floor(Node *root, int x){
    Node *res = NULL;
    while(root != NULL){
        if(root -> key == x) return root;
        else if(root->key > x) root = root -> left;
        else{
            res = root;
            root = root -> right;
        }
    }
    return res;
}

Node *Ceil(Node *root, int x){
    Node *res = NULL;
    while(root != NULL){
        if(root -> key == x) return root;
        else if(root -> key < x) root = root -> right;
        else{
            res = root;
            root = root -> left;
        }
    }
    return res;
}


int main() {

    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int x = 66;
    Node* floor_root = Floor(root, x);

    cout << "The floor of " << x << " is: " << floor_root -> key << endl;

    int y = 66;
    Node * ceil_root = Ceil(root, y);

    cout << "The ceiling of " << y << " is: " << ceil_root -> key << endl;

    return 0;
}