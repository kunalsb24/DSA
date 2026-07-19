# Merge K Sorted Arrays

## Problem Statement

Given `k` sorted arrays, each containing sorted elements, merge them into a **single sorted array**.

### Example

```text
Input:
A1 = {1, 4, 7}
A2 = {2, 5, 8}
A3 = {3, 6, 9}

Output:
1 2 3 4 5 6 7 8 9
```

---

# Approach 1: Naive

1. Copy all elements into one array.
2. Sort the combined array.

### Time Complexity

* Copy elements: **O(N)**
* Sort: **O(N log N)**

where `N` is the total number of elements in all arrays.

---

# Approach 2: Min Heap (Optimal)

## Idea

At any point, the **smallest unprocessed element** must be among the first unprocessed elements of the `k` arrays.

So:

1. Insert the first element of every array into a **Min Heap**.
2. Extract the minimum element.
3. Add it to the result.
4. Insert the next element from the same array (if it exists).
5. Repeat until the heap is empty.

---

## Heap Node

Each heap node stores:

```cpp
(value, arrayIndex, elementIndex)
```

where:

* `value` → current element
* `arrayIndex` → which array it belongs to
* `elementIndex` → its position within that array

---

## Example

Arrays:

```text
A1 = {1,4,7}
A2 = {2,5,8}
A3 = {3,6,9}
```

### Step 1

Insert first element of each array.

Heap:

```text
(1,A1,0)
(2,A2,0)
(3,A3,0)
```

Output:

```text
[]
```

---

### Step 2

Remove

```text
1
```

Output:

```text
1
```

Insert next element from `A1`

```text
4
```

Heap:

```text
2
3
4
```

---

### Step 3

Remove

```text
2
```

Insert

```text
5
```

Heap:

```text
3
4
5
```

Output:

```text
1 2
```

---

### Continue

The output becomes

```text
1 2 3 4 5 6 7 8 9
```

---

# C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    int row;
    int col;

    Node(int v, int r, int c)
    {
        value = v;
        row = r;
        col = c;
    }
};

struct Compare
{
    bool operator()(Node a, Node b)
    {
        return a.value > b.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>> &arr)
{
    priority_queue<Node, vector<Node>, Compare> pq;

    int k = arr.size();

    // Insert first element of every array
    for (int i = 0; i < k; i++)
    {
        pq.push(Node(arr[i][0], i, 0));
    }

    vector<int> result;

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        result.push_back(curr.value);

        // Insert next element from the same array
        if (curr.col + 1 < arr[curr.row].size())
        {
            pq.push(Node(
                arr[curr.row][curr.col + 1],
                curr.row,
                curr.col + 1));
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    vector<int> ans = mergeKArrays(arr);

    for (int x : ans)
        cout << x << " ";
}
```

---

## Output

```text
1 2 3 4 5 6 7 8 9
```

---

# Dry Run

Input:

```text
A1 = {2,6}
A2 = {1,5}
A3 = {3,4}
```

### Initial Heap

```text
2
1
3
```

Output

```text
[]
```

---

Extract

```text
1
```

Insert

```text
5
```

Heap

```text
2
3
5
```

Output

```text
1
```

---

Extract

```text
2
```

Insert

```text
6
```

Heap

```text
3
5
6
```

Output

```text
1 2
```

---

Extract

```text
3
```

Insert

```text
4
```

Heap

```text
4
5
6
```

Output

```text
1 2 3
```

Continue until the heap becomes empty.

Final output:

```text
1 2 3 4 5 6
```

---

# Time Complexity

Let:

* `k` = number of arrays

* `N` = total number of elements

* Initial heap construction: **O(k)**

* Each of the `N` elements is inserted and removed from the heap once: **O(log k)** per operation

Overall:

```text
O(N log k)
```

---

# Space Complexity

* Min Heap stores at most one element from each array:

```text
O(k)
```

* Output array:

```text
O(N)
```

Auxiliary space (excluding the output):

```text
O(k)
```

---

# Comparison

| Approach           | Time           | Extra Space |
| ------------------ | -------------- | ----------- |
| Concatenate + Sort | O(N log N)     | O(N)        |
| Min Heap           | **O(N log k)** | **O(k)**    |

---

# Applications

* Merging multiple sorted files (external sorting)
* Merging results from distributed systems
* Database query processing
* Log file aggregation
* Merge phase of external merge sort

---

# Summary

The optimal solution uses a **Min Heap** containing one element from each array. Each heap node stores the element's value, the array it came from, and its position within that array. After extracting the smallest element, the next element from the same array is inserted into the heap. Since the heap size never exceeds `k`, each heap operation takes **O(log k)** time, giving an overall complexity of **O(N log k)**.


## Merge K Sorted Arrays – Summary of Approaches

| Approach                        | Idea                                                                                                                                    | Time Complexity | Space Complexity                      | Remarks                                                                                                                                     |
| ------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------- | --------------- | ------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| **1. Concatenate + Sort**       | Copy all elements into one array and sort it.                                                                                           | **O(N log N)**  | **O(N)**                              | Simplest approach, but ignores the fact that the input arrays are already sorted.                                                           |
| **2. Repeated Two-Array Merge** | Merge the first two arrays, then merge the result with the third, and so on.                                                            | **O(Nk)**       | **O(N)**                              | Better than sorting in some cases, but becomes inefficient as the number of arrays (`k`) increases. This is the approach used in your code. |
| **3. Min Heap (Optimal)**       | Insert the first element of each array into a min heap. Repeatedly extract the minimum and insert the next element from the same array. | **O(N log k)**  | **O(k)** (excluding the output array) | Best approach. The heap size never exceeds `k`, making each heap operation `O(log k)`.                                                      |

### Variables

* `N` = Total number of elements in all arrays
* `k` = Number of sorted arrays

### Which approach should you use?

* **Approach 1:** Good for a quick and simple implementation.
* **Approach 2:** Suitable for understanding merge operations, but inefficient for large `k`.
* **Approach 3:** Preferred in interviews and real-world applications because it achieves the optimal **O(N log k)** time complexity.
