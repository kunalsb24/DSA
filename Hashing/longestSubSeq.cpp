#include <bits/stdc++.h>
using namespace std;

// Naive: Using Sorting

// int longestConsecutive(int arr[], int n){

//     sort(arr, arr+n);

//     int res = 1;
//     int curr = 1;

//     for(int i = 1; i < n; i++){

//         if(arr[i] == arr[i-1] + 1){

//             curr++;
//         }

//         else if(arr[i] != arr[i-1]){

//             curr = 1;
//         }

//         res = max(res, curr);
//     }

//     return res;
// }

// Optimized: Hashing

int longestConsecutive(int arr[], int n){

    unordered_set<int> s(arr, arr+n);

    int res = 0;

    for(auto x : s){

        // Check if x is start of sequence
        if(s.find(x - 1) == s.end()){

            int curr = 1;

            while(s.find(x + curr) != s.end()){

                curr++;
            }

            res = max(res, curr);
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 2,2,3};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << longestConsecutive(arr, n);
}