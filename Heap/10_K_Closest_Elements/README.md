# K Closest Elements

## Problem Statement

Given:

* A sorted or unsorted array `arr[]`
* An integer `x`
* An integer `k`

Find the **k elements closest to `x`**.

The distance of an element from `x` is:

```text
|arr[i] - x|
```

---

## Example

```text
Input:
arr = {10, 15, 7, 3, 4}
x = 8
k = 2
```

Distances:

| Element | Distance from 8 |
| ------- | --------------: |
| 10      |               2 |
| 15      |               7 |
| 7       |               1 |
| 3       |               5 |
| 4       |               4 |

Closest elements:

```text
7 10
```

---

# Approach 1: Sorting by Distance

### Algorithm

1. Compute the distance of every element from `x`.
2. Sort the elements based on their distance.
3. Print the first `k` elements.

### Time Complexity

```text
O(n log n)
```

---

# Approach 2: Max Heap (Most Efficient)

## Idea

Maintain a **Max Heap of size `k`**.

Each heap node stores:

```cpp
(distance, element)
```

The largest distance among the current `k` closest elements remains at the top.

For every new element:

* If its distance is **smaller** than the heap's top distance:

  * Remove the top.
  * Insert the new element.
* Otherwise, ignore it.

---

## Example

```text
arr = {10,15,7,3,4}
x = 8
k = 2
```

### Step 1

Insert first `k` elements.

Heap stores:

```text
(2,10)
(7,15)
```

Max Heap:

```text
        (7,15)
        /
    (2,10)
```

---

### Step 2

Next element = `7`

Distance:

```text
|7-8| = 1
```

Since

```text
1 < 7
```

Remove

```text
(7,15)
```

Insert

```text
(1,7)
```

Heap:

```text
       (2,10)
       /
    (1,7)
```

---

### Step 3

Next element = `3`

Distance:

```text
5
```

Since

```text
5 > 2
```

Ignore it.

---

### Step 4

Next element = `4`

Distance:

```text
4
```

Ignore it.

Final Heap:

```text
10
7
```

These are the **2 closest elements**.

---

# C++ Implementation

```cpp
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
```

---

## Output

```text
10 7
```

(The order is based on the heap. If you need the output sorted by closeness or value, store the results and sort them afterward.)

---

# Dry Run

Input:

```text
arr = {30,40,32,33,36}
x = 35
k = 3
```

Distances:

| Element | Distance |
| ------- | -------: |
| 30      |        5 |
| 40      |        5 |
| 32      |        3 |
| 33      |        2 |
| 36      |        1 |

### Initial Heap

Insert first three:

```text
(5,30)
(5,40)
(3,32)
```

Top:

```text
(5,40)
```

---

Next element:

```text
33
```

Distance:

```text
2
```

Since

```text
2 < 5
```

Replace the top.

Heap:

```text
(5,30)
(3,32)
(2,33)
```

---

Next element:

```text
36
```

Distance:

```text
1
```

Replace the current maximum distance.

Final heap contains:

```text
36 33 32
```

---

# Time Complexity

* Build heap of size `k`: **O(k)**
* Process remaining `n-k` elements: **O((n-k) log k)**

Overall:

```text
O(n log k)
```

---

# Space Complexity

```text
O(k)
```

---

# Comparison

| Approach            | Time           | Space    |
| ------------------- | -------------- | -------- |
| Sort by distance    | O(n log n)     | O(n)     |
| Max Heap (size `k`) | **O(n log k)** | **O(k)** |

---

# Summary

A **Max Heap of size `k`** is the preferred solution for finding the **k closest elements**. The heap stores `(distance, element)` pairs, ensuring that the farthest among the current `k` closest elements is always at the top. As new elements are processed, closer elements replace farther ones, resulting in an efficient **O(n log k)** algorithm with **O(k)** extra space.
