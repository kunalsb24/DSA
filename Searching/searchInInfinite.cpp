#include<iostream>
using namespace std;

// SEARCH IN AN sorted INFINITE SIZED ARRAY

// Naive Solution

// int search(int arr[], int x){
//     int i = 0;
//     while(true){
//         if(arr[i] == x) return i;
//         if(arr[i]>x) return -1;
//         i++;
//     }
// }
 
// Efficient Solution

int bsearch(int arr[], int low,int high, int x){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == x) return mid;
    else if(arr[mid]>x) return bsearch(arr,low,mid-1,x);
    else return bsearch(arr,mid+1,high,x);
}

int search(int arr[], int x){
    if(arr[0]==x) return 0;
    int i = 1;
    while(arr[i] < x)
        i = i * 2;
    if(arr[i]==x) return i;

    return bsearch(arr, i/2 + 1, i, x);
}

int main(){
    
    int x = 100, arr[]={2,6,8,9,11,80,99,100};
    cout << search(arr,x);

    return 0;
}