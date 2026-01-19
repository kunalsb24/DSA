#include<iostream>
using namespace std;

// Search in sorted rotated array

// Efficient - O(log n) Time

int search(int arr[],int n, int x){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid]==x) return mid;

        if(arr[low] <= arr[mid]){
            if(x >= arr[low] && x < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else{
            if(x > arr[mid] && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n = 6, x = 5, arr[] = {10,20,30,50,5,7};
    cout << "Search index of "<<x << " is "<< search(arr,n,x);
    return 0;
}