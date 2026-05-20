#include <bits/stdc++.h> 
using namespace std; 


// Naive Solution: O(n^2)
// For every character, compare with all the other characters, 
// if it matches set flag = true which means it is a repeating character, 
// if it never matches flag remains false and return that character.

int nonRep(string &str){
    for(int i=0; i<str.length(); i++){
        bool flag = false;
        for(int j=0; j<str.length(); j++){
            if(i!=j && str[i]==str[j]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            return i;
    }
    return -1;
}

// Better Solution: Two traversals, O(n) solution
// 1. create a count array of size 256, initialize it to 0.
// 2. Traverse through all the characters and update the counts.

const int CHAR = 256;
int nonRep(string &str){
    int count[CHAR] = {0};
    for(int i=0; i<str.length(); i++){
        count[str[i]]++;
    }
    for(int i=0; i<str.length(); i++)
        if(count[str[i]] == 1)
            return i;

    return -1;
}


// Efficient Solution: One traversal, O(n)
// 1. create fi array , size 256, initialize to -1.
// 2. Traverse through the string, if fi[str[i]] = -1 i.e. non repeating, store i
// 3. if repeating , store -2.
// 4. Entries which are positive numbers are non-repeating characters
// 5. we return minimum of those numbers.

const int CHAR = 256;
int nonRep(string &str){
    int fi[CHAR];
    fill(fi, fi + CHAR, -1);
    for(int i=0; i<str.length(); i++){
        if(fi[str[i]] == -1)
            fi[str[i]] = i;
        else    
            fi[str[i]] = -2;
    }

    int res = INT_MAX;
    for(int i=0; i<CHAR; i++)
        if(fi[i]>=0)
            res = min(res,fi[i]);
    return (res == INT_MAX)? -1 : res;
}

int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 