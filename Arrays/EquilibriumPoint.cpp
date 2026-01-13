#include <iostream>
using namespace std;

// Equilibrium point: Sum of elements before and after an element are same

bool equilibrium(int arr[], int n){
    int rSum = 0, lSum=0;

    for(int i = 0; i<n; i++)
        rSum += arr[i];
    
    for(int i=0; i<n; i++){
        rSum -= arr[i];
        if(lSum == rSum)
            return true;
        lSum += arr[i];
    }
    return false;
}

int main(){
    int n=6, arr[]={3,4,8,-9,9,7};
    cout << equilibrium(arr,n);
    return 0;
}
	