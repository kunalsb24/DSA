#include<iostream>
using namespace std;

//Naive  -- O(n) time

// int firstOcc(int arr[], int n, int x){
//     for(int i=0; i<n; i++){
//         if(x == arr[i])
//             return i;
//     }
//     return -1;
// }

//Recursive Binary search // O(log n) T, xtra log n space for recursive call.

// int firstOcc(int arr[], int low, int high, int x){
//     if(low>high) return -1;
    
//     int mid = (low + high)/2;
//     if(x>arr[mid])
//         return firstOcc(arr,mid+1,high,x);  // search right half
//     else if(x<arr[mid])
//         return firstOcc(arr, low, mid-1, x); // search left half
//     else{
//         if(mid==0||arr[mid-1]!=arr[mid])   
//             return mid;
//         else
//             return firstOcc(arr,low,mid-1,x);  // keep searching left half
//     }
// }

//Iterative binary search  // THE BEST SOLUTION // O(Log n) time, O(1) xtra Space

int firstOcc(int arr[], int n, int x){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid]>x)
            high = mid - 1;
        else if(arr[mid]<x)
            low = mid + 1;
        else{
            if(mid==0||arr[mid-1]!=arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n = 6, arr[] = {5,10,15,20,20,20};
    int low = 0, high = n-1, x = 20;
    cout << "Index of first occurence is "<<firstOcc(arr,n,x);
    return 0;
}