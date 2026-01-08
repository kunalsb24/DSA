#include <iostream>
using namespace std;

// Naive O(n^2)
int Largest(int arr[], int n){
    for(int i=0; i<n; i++){
        bool flag = true;
        for(int j=0; i<n; j++){
            if(arr[j]>arr[i]){
                flag = false;
                break;
            }
        }
        if(flag==true)
            return i;
    }
    return -1;
}


//Efficient

int Largest(int arr[], int n){
    int res=0;
    for(int i=1; i<n; i++)
        if(arr[i]>arr[res])
            res=i;
    return res;
}

