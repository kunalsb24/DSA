#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node*right;
    Node(int k){
        key=k;
        left=right=NULL;
    }
};

// Recursion
/*
bool search(Node*root, int x){
    if(root==NULL) return false;
    else if(root->key == x) return true;
    else if(root->key > x) return search(root->left, x);
    else return search(root->right, x);
}
*/

// Iterative 
bool search(Node*root, int x){

    while(root!=NULL){
        if(root->key==x) return true;
        else if(root->key > x) root = root->left;
        else root = root->right;
    }
    return false;
}


int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    int x = 80;
    if(search(root, x)) cout << "Key "<< x << " is present" << endl;
    else cout <<"Key is not present" << endl;

    return 0;

}