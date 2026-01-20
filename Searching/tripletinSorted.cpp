#include<iostream>
using namespace std;

bool isPair(int arr[], int n, int sum){
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i]+arr[j] == sum)
            return true;
        else if(arr[i]+arr[j] > sum)
            j--;
        else
            i++;
    }
    return false;
}

bool isTriplet(int arr[], int n, int sum){
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(isPair(arr,n,sum - arr[i]))
                return true;
    
    return false;
}

int main(){
    int n = 7, arr[] = {2,3,4,8,9,20,40}, sum = 32;
    cout << isTriplet(arr,n,sum);
    return 0;
}