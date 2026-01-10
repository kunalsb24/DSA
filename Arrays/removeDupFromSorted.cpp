#include<iostream>
using namespace std;

//Naive
/*
int remDup(int arr[], int n){
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for(int i=1; i<n; i++){
        if(temp[res-1] != arr[i]){
            temp[res] = arr[i];
            res++;
        }
    }

    for(int i=0; i<res; i++){
        arr[i] = temp[i];
    }

    return res;

}

*/

int remDup(int arr[], int n){
    int res = 1;
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[res-1]){
            arr[res] = arr[i];
            res++;
        }
    }
    return res;

}


int main(){
    int n = 11;
    int arr[] = {1,2,2,2,3,3,3,4,4,5,5};
    n = remDup(arr,n);
    
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }

}