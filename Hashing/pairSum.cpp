#include <bits/stdc++.h>
using namespace std;


int pairWithSumX(int arr[],int n, int sum)
{
    unordered_set<int> h;
    for(int i = 0; i < n; i++)
    {
        if(h.find(sum - arr[i]) != h.end())
          return 1;
          
        h.insert(arr[i]);
    }
    return 0;
    
}

int main()
{
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 14;
    
    cout << pairWithSumX(arr, n, sum);
    return 0;
}