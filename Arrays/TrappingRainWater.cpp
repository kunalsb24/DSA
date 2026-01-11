#include<iostream>
using namespace std;

// Naive

// int getWater(int arr[], int n){
//     int res = 0;
//     for(int i=1; i<n-1; i++){
//         int lmax = arr[i];
//         for(int j=0; j<i; j++)
//             lmax = max(lmax, arr[j]);
        
//         int rmax = arr[i];
//         for(int j=i+1; j<n; j++)
//             rmax = max(rmax,arr[j]);
//         res = res + (min(lmax, rmax) - arr[i]);
//     }
//     return res;
// }

// Efficient

int getWater(int arr[], int n){
    int res = 0;
    int lmax[n], rmax[n];

    //Precompute lmax and rmax arrays
    for(int i=0; i<n; i++){
        lmax[i] = max(arr[i],lmax[i-1]);
    }

    for(int i=n-1; i>=0; i--){
        rmax[i] = max(arr[i], rmax[i+1]);
    }

    for(int i=1; i<n-1; i++){
        res = res + (min(lmax[i],rmax[i]) - arr[i]);
    }

    return res;
}


int main(){
    int n = 5, arr[] = {3,0,1,2,5};
    cout << "Trapped Water = "<<getWater(arr,n);
    return 0;
}