#include<iostream>
#include <vector>
using namespace std;

// Given unsorted integers, find the peak element in the array
// A Peak element is an element whose neighbours
// have value smaller than that of element

// Naive
// int peak(int arr[], int n){
//     if(n == 1) return arr[0];
//     if(arr[0] > arr[1]) return arr[0];
//     if(arr[n-1] > arr[n-2]) return arr[n-1];

//     for(int i=1; i<n-1; i++){
//         if((arr[i] >= arr[i-1]) && (arr[i] >= arr[i+1]))
//             return arr[i];
//     }
// }

int peak(int arr[], int n){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if((mid==0 || arr[mid-1] <= arr[mid]) && (mid==n-1 || arr[mid+1] <= arr[mid]))
            return arr[mid];
        if(mid > 0 && arr[mid-1] >= arr[mid]) 
            high = mid - 1;   // Go Left: If the left neighbor is greater/equal,
                               // a peak must exist on the left side (the array is "descending" at mid)
        else
            low = mid + 1;  // Go Right: Otherwise, a peak must exist on the right side 
                             // (the array is "ascending" at mid)
    }
    return -1;
}


int findPeakElement(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Peak is on the right side
            low = mid + 1;
        } else {
            // Peak is on the left side (including mid)
            high = mid;
        }
    }

    return low; // or high (both are same here)
}


int main(){
    int n =5, arr[] = {6,7,8,20,12};
    cout << peak(arr,n);
    return 0;
}
