#include <iostream>
#include <unordered_set>
using namespace std;


// Naive Solution
/*int countDistinct(int arr[], int n){
    int res = 0;
    for(int i=0; i<n; i++){
        bool flag = false;
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            res++;
    }
    return res;
}*/

// using unordered_Set
/*
int countDistinct(int arr[], int n){
    unordered_set<int> s;
    for(int i=0; i<n; i++)
        s.insert(arr[i]);
    return s.size();
}
*/

int countDistinct(int arr[], int n){
    unordered_set<int> s(arr, arr+n);
    return s.size();
}


int main() {

    int arr[] = {10,20,10,30,50}, n = 5;
    cout << countDistinct(arr,n);
    return 0;
}
