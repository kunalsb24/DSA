#include <iostream>
using namespace std;

// Find the max sum of k consecutive elements

// int maxSum(int arr[], int n, int k){
//     int res = 0;
//     for(int i=0; i<=n-k;i++){
//         int sum = 0;
//         for(int j = i; j<i+k; j++){
//             sum += arr[j];
//         }
//         res = max(res,sum);
//     }
//     return res;
// }


// window sliding technique

int maxSum(int arr[], int n, int k){
    int curr = 0;
    for(int i=0 ;i<k; i++)
        curr += arr[i];
    int res = curr;
    for(int i=k; i<n; i++){
        curr = curr + arr[i] - arr[i-k];
        res = max(res,curr);
    }
    return res;
}


int main(){
    int n = 6, arr[] = {1,8,30,-5,20,7}, k=3;

    cout << "Max sum is " << maxSum(arr,n,k);

    return 0;

}