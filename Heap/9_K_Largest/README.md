# K Largest Elements

## Problem Statement

Given an array of `n` elements and an integer `k`, find the **k largest elements** in the array.

### Example

```text
Input:
arr = {5, 15, 10, 20, 8}
k = 2

Output:
20 15
```

---

# Approach 1: Sorting

### Algorithm

1. Sort the array in ascending order.
2. Print the last `k` elements.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    sort(arr, arr + n);

    for (int i = n - 1; i >= n - k; i--)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {5, 15, 10, 20, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    kLargest(arr, n, 2);
}
```

### Time Complexity

* Sorting: **O(n log n)**
* Printing: **O(k)**

Overall:

```text
O(n log n)
```

---

# Approach 2: Using a Max Heap

### Idea

1. Build a Max Heap from all elements.
2. Extract the maximum element `k` times.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    while (k--)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {5, 15, 10, 20, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    kLargest(arr, n, 2);
}
```

### Dry Run

Array:

```text
5 15 10 20 8
```

Max Heap:

```text
        20
      /    \
    15      10
   /  \
  5    8
```

Extract 1:

```text
20
```

Extract 2:

```text
15
```

Output:

```text
20 15
```

### Time Complexity

* Build Heap: **O(n)**
* `k` extractions: **O(k log n)**

Overall:

```text
O(n + k log n)
```

---

# Approach 3: Using a Min Heap of Size `k` (Most Efficient)

### Idea

Maintain a **Min Heap** containing only the `k` largest elements seen so far.

1. Insert the first `k` elements into a Min Heap.
2. For each remaining element:

   * If it is greater than the heap's minimum (`pq.top()`):

     * Remove the minimum.
     * Insert the new element.
3. At the end, the heap contains the `k` largest elements.

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    int arr[] = {5, 15, 10, 20, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    kLargest(arr, n, 2);
}
```

### Dry Run

Input:

```text
arr = {5, 15, 10, 20, 8}
k = 2
```

#### Step 1

Insert first `k` elements:

```text
5 15
```

Min Heap:

```text
    5
   /
 15
```

#### Step 2

Next element = `10`

Since:

```text
10 > 5
```

Remove `5` and insert `10`.

Heap:

```text
   10
  /
15
```

#### Step 3

Next element = `20`

```text
20 > 10
```

Heap becomes:

```text
   15
  /
20
```

#### Step 4

Next element = `8`

```text
8 < 15
```

Ignore it.

Final heap:

```text
15 20
```

These are the **2 largest elements**.

### Time Complexity

* Build heap of size `k`: **O(k)**
* Process remaining `n - k` elements: **O((n - k) log k)**

Overall:

```text
O(n log k)
```

### Space Complexity

```text
O(k)
```

---

# Comparison

| Approach            | Time Complexity | Space Complexity |
| ------------------- | --------------- | ---------------- |
| Sorting             | O(n log n)      | O(1)             |
| Max Heap            | O(n + k log n)  | O(n)             |
| Min Heap (size `k`) | **O(n log k)**  | **O(k)**         |

---

# Summary

* **Sorting** is simple but unnecessarily sorts the entire array.
* **Max Heap** is useful when repeatedly extracting the largest elements.
* **Min Heap of size `k`** is the most efficient approach for a single query, with **O(n log k)** time and **O(k)** extra space, making it the preferred solution in interviews.
