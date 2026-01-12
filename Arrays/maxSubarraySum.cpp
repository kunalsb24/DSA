#include <iostream>
using namespace std;

//Naive
// int maxSum(int arr[], int n){
//     int res=0;
//     for(int i=0; i<n; i++){
//         int curr=0;
//         for(int j=i; j<n; j++){
//             curr = curr+arr[j];
//             res = max(curr, res);
//         }
//     }
//     return res;
// }

//Efficient
// Compute max sum ending with that element

int maxSum(int arr[], int n){
    int res = arr[0];
    int maxEnding = arr[0];

    for(int i=1; i<n; i++){
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}

int main(){
    int n=7, arr[] = {2,3,-8,7,-1,2,3};
    cout << "MaxSum is " << maxSum(arr,n);
    return 0;
}