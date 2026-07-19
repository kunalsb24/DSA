#include <bits/stdc++.h>
using namespace std;

void kClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> pq;

    // Insert first k elements
    for (int i = 0; i < k; i++)
        pq.push({abs(arr[i] - x), arr[i]});

    // Process remaining elements
    for (int i = k; i < n; i++)
    {
        int dist = abs(arr[i] - x);

        if (dist < pq.top().first)
        {
            pq.pop();
            pq.push({dist, arr[i]});
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {10, 15, 7, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;
    int x = 8;

    kClosest(arr, n, k, x);
}