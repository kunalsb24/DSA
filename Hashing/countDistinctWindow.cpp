#include <bits/stdc++.h>
using namespace std;

void countDistWin(int arr[], int n, int k){

    unordered_map<int,int> freq;

    // First window
    for(int i = 0; i < k; i++){

        freq[arr[i]]++;
    }

    cout << freq.size() << " ";

    // Remaining windows
    for(int i = k; i < n; i++){

        // Remove outgoing element
        freq[arr[i-k]]--;

        // Remove if frequency becomes 0
        if(freq[arr[i-k]] == 0)
            freq.erase(arr[i-k]);

        // Add incoming element
        freq[arr[i]]++;

        cout << freq.size() << " ";
    }
}

