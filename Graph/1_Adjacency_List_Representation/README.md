# Comparison: Adjacency Matrix vs Adjacency List

| Feature                    | Adjacency Matrix           | Adjacency List                            |
| -------------------------- | -------------------------- | ----------------------------------------- |
| **Representation**         | 2D array of size **V × V** | Array (or vector) of linked lists/vectors |
| **Space Complexity**       | **O(V²)**                  | **O(V + E)**                              |
| **Edge Search**            | **O(1)**                   | **O(Degree of Vertex)**                   |
| **Add Edge**               | **O(1)**                   | **O(1)**                                  |
| **Delete Edge**            | **O(1)**                   | **O(Degree of Vertex)**                   |
| **Traverse All Neighbors** | **O(V)**                   | **O(Degree of Vertex)**                   |
| **Best For**               | Dense graphs               | Sparse graphs                             |
| **Memory Usage**           | High                       | Low                                       |
| **Implementation**         | Simple                     | Slightly more complex                     |

---

## Adjacency Matrix

### Advantages

* Simple to implement.
* Edge existence can be checked in **O(1)** time.
* Best for **dense graphs** (many edges).

### Disadvantages

* Requires **O(V²)** memory.
* Wastes space for sparse graphs.

---

## Adjacency List

### Advantages

* Uses **O(V + E)** memory.
* Efficient for **sparse graphs**.
* Faster traversal of adjacent vertices.
* Preferred for **BFS** and **DFS** algorithms.

### Disadvantages

* Checking if a specific edge exists is slower.
* Slightly more complex to implement.

---

## When to Use?

* **Use Adjacency Matrix** when:

  * The graph is **dense**.
  * Frequent edge lookups are required.

* **Use Adjacency List** when:

  * The graph is **sparse**.
  * Memory efficiency is important.
  * Performing graph traversals like **BFS** and **DFS**.

---

## Exam Summary

| Adjacency Matrix          | Adjacency List                      |
| ------------------------- | ----------------------------------- |
| Uses a **2D array**       | Uses **lists/vectors of neighbors** |
| Space = **O(V²)**         | Space = **O(V + E)**                |
| Fast edge lookup          | Memory efficient                    |
| Best for **dense graphs** | Best for **sparse graphs**          |
