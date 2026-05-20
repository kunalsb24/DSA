#include <iostream>
#include <unordered_set>
using namespace std;

int union_(int a[], int b[], int m, int n){
    unordered_set<int> h(a,a+m);
    // for(int i=0; i<m; i++){
    //     h.insert(a[i]);
    // }
    for(int i=0; i<n; i++){
        h.insert(b[i]);
    }
    return h.size();
}

int main(){
    int a[] = {10,30,10}, b[]={20,10,50}, m = 3, n = 3;
    cout << union_(a,b,m,n);
    return 0;
}