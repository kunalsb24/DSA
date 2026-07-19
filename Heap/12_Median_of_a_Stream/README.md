# Median of a Stream

## Problem Statement

Given a stream of numbers arriving one by one, find the **median after each insertion**.

The **median** is:

* **Odd number of elements:** Middle element.
* **Even number of elements:** Average of the two middle elements.

---

## Example

Input Stream:

```text
5, 15, 1, 3
```

Output:

```text
After 5      → 5
After 15     → 10
After 1      → 5
After 3      → 4
```

---

# Naive Approach

For every new element:

1. Insert it into an array.
2. Sort the array.
3. Find the median.

### Time Complexity

* Insert: **O(1)**
* Sort: **O(n log n)**

For `n` insertions:

```text
O(n² log n)
```

Too slow for a continuous stream.

---

# Efficient Approach: Two Heaps

## Idea

Maintain two heaps:

* **Max Heap (`left`)** → Stores the smaller half of the numbers.
* **Min Heap (`right`)** → Stores the larger half of the numbers.

```text
          Median
      ----------------
      Max Heap | Min Heap
     (Smaller) | (Larger)
```

### Properties

1. Every element in the max heap is **≤** every element in the min heap.
2. The size difference between the heaps is at most **1**.

---

## Finding the Median

### Case 1: Both heaps have the same size

Median:

```text
(left.top() + right.top()) / 2
```

---

### Case 2: Max Heap has one extra element

Median:

```text
left.top()
```

---

### Case 3: Min Heap has one extra element

Median:

```text
right.top()
```

---

# Algorithm

For every incoming element `x`:

1. If the max heap is empty or `x <= left.top()`, insert into the max heap.
2. Otherwise, insert into the min heap.
3. Rebalance the heaps if their sizes differ by more than 1.
4. Compute the median based on heap sizes.

---

# Example

Stream:

```text
5 15 1 3
```

---

### Insert 5

Max Heap:

```text
5
```

Min Heap:

```text
(empty)
```

Median:

```text
5
```

---

### Insert 15

Since

```text
15 > 5
```

Min Heap:

```text
15
```

Heaps:

```text
Left : 5
Right: 15
```

Median:

```text
(5+15)/2 = 10
```

---

### Insert 1

Insert into max heap.

Left:

```text
5
1
```

Right:

```text
15
```

Median:

```text
5
```

---

### Insert 3

Insert into left.

Left becomes

```text
5
1
3
```

Now size difference is 2.

Move the maximum (`5`) to the right heap.

Left:

```text
3
1
```

Right:

```text
5
15
```

Median:

```text
(3+5)/2 = 4
```

---

# C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class MedianStream
{
    priority_queue<int> left;   // Max Heap
    priority_queue<int, vector<int>, greater<int>> right; // Min Heap

public:
    void insert(int x)
    {
        if (left.empty() || x <= left.top())
            left.push(x);
        else
            right.push(x);

        // Rebalance
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    double getMedian()
    {
        if (left.size() == right.size())
            return (left.top() + right.top()) / 2.0;

        if (left.size() > right.size())
            return left.top();

        return right.top();
    }
};

int main()
{
    MedianStream ms;

    int arr[] = {5, 15, 1, 3};

    for (int x : arr)
    {
        ms.insert(x);
        cout << "Median = " << ms.getMedian() << endl;
    }
}
```

---

## Output

```text
Median = 5
Median = 10
Median = 5
Median = 4
```

---

# Dry Run

| Stream   | Max Heap (Left) | Min Heap (Right) | Median |
| -------- | --------------- | ---------------- | ------ |
| 5        | 5               | -                | 5      |
| 5,15     | 5               | 15               | 10     |
| 5,15,1   | 5,1             | 15               | 5      |
| 5,15,1,3 | 3,1             | 5,15             | 4      |

---

# Time Complexity

For each insertion:

* Insert into heap: **O(log n)**
* Rebalancing: **O(log n)**
* Find median: **O(1)**

Overall:

| Operation  | Complexity   |
| ---------- | ------------ |
| Insert     | **O(log n)** |
| Get Median | **O(1)**     |

---

# Space Complexity

Both heaps together store all elements.

```text
O(n)
```

---

# Comparison

| Approach                   | Insert       | Median   | Overall        |
| -------------------------- | ------------ | -------- | -------------- |
| Sort after every insertion | O(n log n)   | O(1)     | O(n² log n)    |
| Two Heaps                  | **O(log n)** | **O(1)** | **O(n log n)** |

---

# Summary

The optimal solution uses **two heaps**:

* A **Max Heap** stores the smaller half of the elements.
* A **Min Heap** stores the larger half.

After each insertion, the heaps are rebalanced so that their sizes differ by at most one. The median is then obtained in **O(1)** time from the heap tops, while each insertion takes **O(log n)**. This makes the two-heap approach ideal for processing a continuous stream of numbers.
