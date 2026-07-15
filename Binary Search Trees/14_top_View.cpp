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

void topView(Node *root)
{
    if (root == NULL)
        return;

    map<int, int> mp;
    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        Node *curr = p.first;
        int hd = p.second;

        // Store only the first node at this HD
        if (mp.find(hd) == mp.end())
            mp[hd] = curr->key;

        if (curr->left)
            q.push({curr->left, hd - 1});

        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    for (auto p : mp)
        cout << p.second << " ";
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

    topView(root);
}
