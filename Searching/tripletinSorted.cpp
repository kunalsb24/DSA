#include<iostream>
using namespace std;

bool isPair(int arr[], int n, int sum, int si){
    int i = si, j = n-1;
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
    for(int i=0; i < n-2; i++)
        for(int j=i+1; j<n; j++)
            if(isPair(arr,n,sum - arr[i],i+1))
                return true;    
    return false;
}

// Prints all the possible triplets

void printTriplets(int arr[], int n, int sum){
    for(int i = 0; i < n - 2; i++){
        int l = i + 1;
        int r = n - 1;

        while(l < r){
            int s = arr[i] + arr[l] + arr[r];

            if(s == sum){
                cout << "(" << arr[i] << ", "
                            << arr[l] << ", "
                            << arr[r] << ")" << endl;
                l++;
                r--;
            }
            else if(s < sum){
                l++;
            }
            else{
                r--;
            }
        }
    }
}


int main(){
    int n = 7, arr[] = {2,3,4,8,9,20,40}, sum = 32;

    if(isTriplet(arr,n, sum))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    printTriplets(arr,n,sum);
    return 0;
}