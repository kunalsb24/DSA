#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Build Max Heap

void buildHeap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}
    

// Heap Sort
void heapSort(int arr[], int n)
{
    // Call Build Heap
    buildHeap(arr,n);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current maximum to the end
        swap(arr[0], arr[i]);

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {10, 5, 20, 2, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted Array:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}