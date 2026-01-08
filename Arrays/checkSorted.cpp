#include <iostream>
using namespace std;

// Naive

bool isSorted(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[i])
                return false;
        
    }
    return true;
}


// Efficient

bool isSorted(int arr[], int n){
    for(int i=0; i<n; i++)
        if(arr[i]<arr[i-1])
            return false;
    return true;
}
