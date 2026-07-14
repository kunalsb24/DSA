#include <bits/stdc++.h>
#include<queue>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left;
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void vTraversal(Node *root){
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while(q.empty() == false){
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left != NULL)
            q.push({curr->left, hd-1});
        if(curr->right != NULL)
            q.push({curr->right, hd+1});

    }

    for(auto p: mp){
            vector<int> v = p.second;
            for(int x: v)
                cout << x << " ";
            cout << endl;
        }
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);

    vTraversal(root);
}