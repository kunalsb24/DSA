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

     int main() {
            int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
            int n = sizeof(arr)/sizeof(arr[0]);
            int sum = 4;
            cout << maxLen(arr, n, sum);
     }