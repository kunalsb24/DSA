#include <iostream>
using namespace std;

// Iterative solution
/*
int sumofNNos(int n){
    if(n==0)
        return 0;
    
    return n*(n+1)/2;
}

int main(){
    cout<<sumofNNos(3)<<endl;
    return 0;
}
*/

// Recursive solution //


int getsum(int n){
    if(n==0)
        return 0;
    
    return n + getsum(n-1);
}

int main(){
    cout<<getsum(5)<<endl;
    return 0;
}

