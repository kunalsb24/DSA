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

// Method 1: Naive O(n^2)

// int height(Node*root){
//     if(root==NULL) return 0;
//     else
//         return 1 + max(height(root->left), height(root->right));
// }

// int diameter(Node*root){
//     if(root==NULL) return 0;

//     int d1 = 1 + height(root->left) + height(root->right);
//     int d2 = diameter(root->left);
//     int d3 = diameter(root->right);

//     return max(d1, max(d2,d3));
// }

// -----------------------------------------------------------------

// Efficient: O(n)

int res = 0;
int height(Node*root){
      if(root==NULL) return 0;
    
      int lh = height(root->left);
      int rh = height(root->right);

      res = max(res, lh+rh+1);
      return 1 + max(lh,rh);

}


int main(){
    Node *root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> left -> left = new Node(40);
    root -> left -> right = new Node(50);
    root -> right -> right = new Node(70);
    root -> right -> right -> right = new Node(80);

    cout<<"Height: "<<height(root)<<endl;
    cout << "Diameter of the given Binary tree is: " << res << endl;

    return 0;

}