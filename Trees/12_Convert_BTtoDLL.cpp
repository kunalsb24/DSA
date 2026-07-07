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

void printList(Node*head){
    Node*curr = head;
    while(curr != NULL){
        cout << curr->key << " ";
        curr = curr -> right;
    } cout << endl;
}

Node *prevNode = NULL;
Node *BTtoDLL(Node*root){
    
    if(root==NULL) return root;
    Node*head = BTtoDLL(root->left);
    if(prevNode == NULL){head = root;}
    else{
        root -> left = prevNode;
        prevNode -> right = root;
    }
    prevNode = root;
    BTtoDLL(root->right);
    return head;
}


int main(){

    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    Node *head=BTtoDLL(root);
	printList(head);
    
    
    return 0;

}