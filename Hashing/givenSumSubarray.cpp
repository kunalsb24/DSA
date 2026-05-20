#include <bits/stdc++.h>
using namespace std;

bool isSubarraySum(int arr[], int n, int sum){

    unordered_set<int> s;

    int prefix_sum = 0;

    for(int i = 0; i < n; i++){

        prefix_sum += arr[i];

        // Case 1: subarray from beginning
        if(prefix_sum == sum)
            return true;

        // Case 2: required prefix exists
        if(s.find(prefix_sum - sum) != s.end())
            return true;

        // Store prefix sum
        s.insert(prefix_sum);
    }

    return false;
}