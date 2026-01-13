#include <iostream>
using namespace std;

// Given array of non negative integers and an integer sum
// Find the subarray that is same as given sum

bool isSubSum(int arr[], int n, int sum){
    int s = 0, curr = 0;
    for(int e = 0; e<n; e++){
        curr += arr[e];
        while(sum<curr){
            curr -= arr[s];
            s++;
        }
        if(curr==sum)
            return true;
    }
    return false;
}

int main(){
    int n = 4, sum = 17, arr[] = {4,8,12,5};
    cout << isSubSum(arr,n,sum);
    return 0;
}