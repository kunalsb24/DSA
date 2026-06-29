#include<bits/stdc++.h>
#include<queue>
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

// Method 1: Recursive

int maxLevel = 0;
void printLeft(Node*root, int level){
    if(root==NULL) return;
    if(maxLevel < level){
        cout << (root->key) << " ";
        maxLevel = level;
    }
    printLeft(root->left, level+1);
    printLeft(root->right, level+1);
}

void printLeftView(Node*root){
    printLeft(root, 1);
}


// Method 2: Iterative

/*
void printLeftView(Node *root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        int count = q.size();
        for(int i=0; i<count; i++){
            Node*curr = q.front();
            q.pop();
            if(i==0)
                cout << (curr->key) << " ";
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}
    */

int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    printLeftView(root);
    

    return 0;

}


