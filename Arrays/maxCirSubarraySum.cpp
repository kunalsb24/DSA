#include <iostream>
using namespace std;

//Naive

// int maxCirSum(int arr[], int n){
//     int res = arr[0];
//     for(int i=0; i<n; i++){
//         int curr_max=arr[i];
//         int curr_sum=arr[i];

//         for(int j=1; j<n; j++){
//             int index = (i+j)%n;
//             curr_sum += arr[index];
//             curr_max = max(curr_max, curr_sum);
//         }
//         res = max(res,curr_max);
//     }
//     return res;
// }

// Efficient -- Kadane's Algorithm

int normalMaxSum(int arr[], int n){
    int res=arr[0], maxEnding=arr[0];
    for(int i=1; i<n; i++){
        maxEnding=max(arr[i], maxEnding+arr[i]);
        res = max(res,maxEnding);
    }
    return res;
}

int maxCirSum(int arr[], int n){
    //Normal Sum
    int max_normal = normalMaxSum(arr,n);
    if(max_normal<0)
        return max_normal;

    // Circular Sum
    int arr_sum=0;
    for(int i=0; i<n; i++){
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalMaxSum(arr,n);
    return max(max_normal, max_circular);
}

int main(){
    int n = 4, arr[] = {5,-2,3,4};
    cout << "Max Circular Subarray sum is: " << maxCirSum(arr,n);
    return 0;
}