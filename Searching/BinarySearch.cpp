#include<iostream>
using namespace std;

// iterative

// int bsearch(int arr[], int n, int x){
//     for(int i=0; i<n; i++){
//         if(x==arr[i])
//             return i;
//     }
//     return -1;
// }

// Recursive O(log n)

int bsearch(int arr[], int low,int high, int x){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == x) return mid;
    else if(arr[mid]>x) return bsearch(arr,low,mid-1,x);
    else return bsearch(arr,mid+1,high,x);
}


int main(){
    int n = 5, x = 20, arr[] = {10,20,30,40,50};
    cout << bsearch(arr,0, n-1, x);
    return 0;
}