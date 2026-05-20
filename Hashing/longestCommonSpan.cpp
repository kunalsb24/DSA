#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n, int sum){
    unordered_map<int, int> mp;
    int pre_sum = 0, res = 0;
    for(int i=0; i<n; i++){
        pre_sum += arr[i];

        if(pre_sum == sum)
            res = i+1;
        
        if(mp.find(pre_sum) == mp.end())
            mp[pre_sum] = i;
        
        if(mp.find(pre_sum - sum) != mp.end())
            res = max(res, i-mp[pre_sum-sum]);
    }
    return res;
}

int maxCommon(int arr1[], int arr2[], int n){

    int temp[n];
    for(int i=0; i<n; i++)
        temp[i] = arr1[i] - arr2[i];
    
    return maxLen(temp,n,0);
}

int main(){
    int arr1[] = {0,1,0,0,0,0}, arr2[] = {1,0,1,0,0,1}, n = 6;
    cout << maxCommon(arr1,arr2,n);
    return 0;
}