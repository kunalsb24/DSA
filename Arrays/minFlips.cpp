#include <iostream>
using namespace std;

// Given Binary array, convert this array into an array that 
// either contains all 1's or all 0's.
//  We need to do it using the minimum number of group flips.

void printGroups(int arr[], int n){
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            if(arr[i]!=arr[0])
                cout << "From "<<i <<" to ";
            else
                cout << (i-1) << endl;
        }
    }
    if(arr[n-1]!=arr[0])        // To handle the last group having a single element
        cout << (n-1) << endl;   // ex: arr[] = {0,0,1,1,0,0,1,1,0,1}   last group is {1}
}

int main(){
    int n = 9;
    int arr[] = {0,0,1,1,0,0,1,1,0,1};
    printGroups(arr,n);
    return 0;
}

// we never flip the first group
// we only flip the second group

//ex : {1,1,0,0,0,1,1,0,0,1}
// Here there are 3 groups of 1's and 2 groups of 0's


