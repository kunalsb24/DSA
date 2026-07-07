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

// Method 1

// void treeTraversalSpiral(Node * root){
//     if(root==NULL) return;
//     queue<Node*> q;
//     stack<int> s;
//     bool reverse = false;
//     q.push(root);
//     while(q.empty()==false){
//         int count = q.size();
//         for(int i=0; i<count; i++){
//             Node*curr = q.front();
//             q.pop();
//             if(reverse)
//                 s.push(curr->key);
//             else
//                 cout << curr->key << " ";
//             if(curr->left!=NULL)
//                 q.push(curr->left);
//             if(curr->right!=NULL)
//                 q.push(curr->right);
//         }
//         if(reverse){
//             while(s.empty()==false){
//                 cout << s.top() << " ";
//                 s.pop();
//             }
//         }
//         reverse = !reverse;

//         cout<< endl ;
//     }
// }

//------------------------------------------------------------------------------

// Method 2

void treeTraversalSpiral(Node * root){
    stack<Node*> s1, s2;

    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node *curr = s1.top();
            s1.pop();
            cout << curr->key << " ";
            if(curr->left) s2.push(curr->left);
            if(curr->right) s2.push(curr->right);
            
        }
         while(!s2.empty()){
            Node *curr = s2.top();
            s2.pop();
            cout << curr->key << " ";
            if(curr->right) s1.push(curr->right);
            if(curr->left) s1.push(curr->left);
        }
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

    treeTraversalSpiral(root);

    return 0;

}