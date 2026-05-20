#include <bits/stdc++.h>
using namespace std;

bool isZeroSum(int arr[], int n){

    unordered_set<int> s;

    int prefix_sum = 0;

    for(int i = 0; i < n; i++){

        prefix_sum += arr[i];

        // Case 1: prefix sum itself is 0
        if(prefix_sum == 0)
            return true;

        // Case 2: same prefix sum already exists
        if(s.find(prefix_sum) != s.end())
            return true;

        // Store prefix sum
        s.insert(prefix_sum);
    }

    return false;
}

int main(){
    int arr[] = {1,4,13,-3,-10,5}, n = 6;
    
    if(isZeroSum(arr,n))
        cout<< "True";
    else
        cout << "False";

    return 0;
}