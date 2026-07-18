#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void sortKSorted(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert first k+1 elements
    int i;
    for (i = 0; i <= k && i < arr.size(); i++)
        pq.push(arr[i]);

    int index = 0;

    // Process remaining elements
    while (i < arr.size())
    {
        arr[index++] = pq.top();
        pq.pop();

        pq.push(arr[i]);
        i++;
    }

    // Remove remaining elements
    while (!pq.empty())
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    sortKSorted(arr, k);

    for (int x : arr)
        cout << x << " ";

    return 0;
}