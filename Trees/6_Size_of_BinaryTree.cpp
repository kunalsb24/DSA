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

int  sizeOfBinaryTree(Node*root){
    if(root==NULL) return 0;
    else{
        return (1 + sizeOfBinaryTree(root->left) 
        + sizeOfBinaryTree(root->right));
    }
}

int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    cout<< "Size of Binary Tree is: "<< sizeOfBinaryTree(root)<< endl;

    return 0;

}