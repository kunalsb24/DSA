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

int max0sAnd1s(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            arr[i] = -1;
    }

    return maxLen(arr,n,0);

}

int main(){
    int arr[] = {1,0,1,1,1,0,0}, n=7;
    cout << max0sAnd1s(arr,n);
    return 0;
}