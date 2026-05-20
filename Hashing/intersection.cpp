#include <iostream>
#include <unordered_set>
using namespace std;

// Naive

// void intersection(int a[], int b[], int m, int n){
//     for(int i=0; i<m; i++){
//         bool flag = false;
//         for(int j=0; j<n; j++){
//             if(a[i] == b[j]){
//                 flag = true;
//                 break;
//             }
//         }

//         if(flag == true)
//             cout << a[i] << " ";
//     }
// }

// hashing technique

void intersection(int a[], int b[], int m, int n){
    unordered_set<int> s(b, b+n);
    for(int i=0; i<m; i++){
        if(s.find(a[i]) != s.end())   // if a[i] is present
            cout << a[i] << " ";
            s.erase(a[i]);   // avoids duplicates
    }
}

int main(){
    int a[] = {10,15,20,25,30,50}, b[] = {30, 5, 15,80}, m = 6, n = 4;
    intersection(a,b,m,n);
    return 0;
}