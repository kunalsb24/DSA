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

// Recursive
/*
Node *insert(Node *root, int x){
    if(root==NULL) return new Node(x);
    else if(root->key < x) root->right=insert(root->right, x);
    else if(root->key > x) root->left=insert(root->left, x);
    return root;
}
*/

// Iterative

Node *insert(Node *root, int x){
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while(curr!=NULL){
        parent = curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }

    if(parent==NULL)
        return temp;
    if(parent->key > x)
        parent->left = temp;
    else
        parent->right = temp;
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
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

    int x=100;
	
	root=insert(root,x);
	inorder(root);

    return 0;

}