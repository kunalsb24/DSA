#include<iostream>
using namespace std;

//Naive
/*
void moveToEnd(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            for(int j=i+1; j<n; j++)
                if(arr[j]!=0)
                    swap(arr[i], arr[j]);
        }
    }
}
*/

//Efficient
void moveToEnd(int arr[], int n){
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

int main(){
    int n = 8;
    int arr[] = {10,5,0,0,8,0,9,0};
    moveToEnd(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] <<" ";
    }

}