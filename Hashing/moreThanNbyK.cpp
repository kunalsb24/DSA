#include <bits/stdc++.h>
using namespace std;

// Naive
/*
void printNByK(int arr[], int n, int k)
{
    sort(arr,arr+n);
    int i=1,count=1;
    while(i<n){
        while(i<n&& arr[i]==arr[i-1]){
            count++;
            i++;
        }
        if(count>n/k)
            cout<<arr[i-1]<<" ";
        count=1;
        i++;
    }
    
}
*/

// Optimized: Hashing

// void printNByK(int arr[], int n, int k)
// {
//     unordered_map<int,int> m;
    
//     for(int i=0;i<n;i++)
//         m[arr[i]]++;
//     for(auto e: m)
//         if(e.second>n/k)
//             cout<<e.first<<" ";
    
// }

// Moore's Voting Generalization for more than n/k

void moreThanNbyK(int arr[], int n, int k){

    unordered_map<int,int> mp;

    // Phase 1: Find candidates
    for(int i = 0; i < n; i++){

        // Existing candidate
        if(mp.find(arr[i]) != mp.end()){

            mp[arr[i]]++;
        }

        // Space available
        else if(mp.size() < k - 1){

            mp[arr[i]] = 1;
        }

        // Cancellation step
        else{

            for(auto x = mp.begin(); x != mp.end(); ){

                x->second--;

                if(x->second == 0)
                    x = mp.erase(x);
                else
                    x++;
            }
        }
    }

    // Phase 2: Verify actual frequencies
    for(auto x : mp){

        int count = 0;

        for(int i = 0; i < n; i++){

            if(arr[i] == x.first)
                count++;
        }

        if(count > n/k)
            cout << x.first << " ";
    }
}


int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10,10};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    moreThanNbyK(arr, n, k);
}