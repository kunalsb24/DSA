#include <iostream>
using namespace std;

// Majority element in an array of size n is the element
// which appears more than n/2 times in the array

//Naive

// int findMajority(int arr[], int n){
//     for(int i=0; i<n; i++){
//         int count = 1;
//         for(int j=i+1; j<n; j++){
//             if(arr[i]==arr[j])
//                 count++;
//         }
//         if(count>n/2)
//             return i;
//     }
//     return -1;
// }

// Efficient -- Moore's Voting Algorithm

int findMajority(int arr[], int n){
    int res = 0, count = 1;
    for(int i=0; i<n; i++){
        if(arr[res] == arr[i])
            count++;
        else
            count--;
        if(count == 0 ){
            res = i;
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i<n; i++){
        if(arr[res]==arr[i])
            count++;
    }
    if(count<=n/2)
        res=-1;
    
    return res;
}

int main(){
    int n = 8, arr[] = {8,7,6,8,6,6,6,6};
    cout << "Majority element index is "<<findMajority(arr,n);
    return 0;
}
