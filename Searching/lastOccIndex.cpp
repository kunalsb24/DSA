#include<iostream>
using namespace std;

// Iterative
int lastOcc(int arr[], int n, int x){
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] < x)
            low = mid+1;
        else if(arr[mid] > x)
            high = mid - 1;
        else{
            if(mid == n-1 || arr[mid+1] != arr[mid])
                return mid;
            else
                low = mid+1;
        }
    }
    return -1;
}

// Recursive Binary search

int lastOccurence(int arr[], int low, int high, int x, int n){
    if(low>high) return -1;

    int mid = (low + high)/2;
    if(x > arr[mid])
        return lastOccurence(arr, mid+1, high, x,n);
    else if(x < arr[mid])
        return lastOccurence(arr, low, mid-1, x,n);
    else{
        if(mid==n-1 || arr[mid+1]!=arr[mid])
            return mid;
        else
            return lastOccurence(arr,mid+1,high,x,n);
    }
}

int main(){
    int n = 6, arr[] = {5,10,15,20,20,20};
    int x = 20;
    int low = 0, high = n-1;
    cout << "Index of last occurence is "<<lastOcc(arr,n,x);
    cout << "Index of Last Occurence is "<<lastOccurence(arr,low,high,x,n);
    return 0;
}