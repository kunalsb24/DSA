#include<iostream>
using namespace std;

// Given sorted array and Sum, Determine whether there exists 
// pair of elements equal to the given sum.

// Naive solution

// bool isPair(int arr[], int n, int sum){
//     for(int i=0; i<n-1; i++){
//         for(int j = i+1; j<n; j++){
//             if(arr[i]+arr[j]==sum)
//                 return true;
//         }
//     }
//     return false;
// }

// Two Pointer Approach

bool isPair(int arr[], int n, int sum){
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i]+arr[j] == sum)
            return true;
        else if(arr[i]+arr[j] > sum)
            j--;
        else
            i++;
    }
    return false;
}


int main(){
    int n = 4, arr[] = {2,3,8,11}, sum = 14;
    cout << isPair(arr,n,sum);
    return 0;
}
