Here are **brief notes** based on the slides you shared.

# Graph Data Structure – Short Notes

## 1. Introduction to Graph

* A **Graph** is a non-linear data structure used to represent relationships between objects.
* It is represented as:
  [
  G = (V, E)
  ]
  where:

  * **V** = Set of vertices (nodes)
  * **E** = Set of edges (connections)

**Example:**

```
V = {V1, V2, V3, V4, V5}

E = {(V1,V2), (V1,V3), (V2,V4),
     (V3,V4), (V3,V5), (V4,V5)}
```

---

## 2. Directed vs Undirected Graph

### Directed Graph (Digraph)

* Edges have a direction (→).
* Edge (A → B) means movement is only from A to B.

### Undirected Graph

* Edges have no direction.
* Edge (A—B) means movement is possible in both directions.

---

## 3. Degree of a Vertex

### In Undirected Graph

* **Degree(v)** = Number of edges connected to the vertex.

**Properties**

* Sum of all vertex degrees = **2 × |E|**
* Maximum edges:
  [
  \frac{|V|(|V|-1)}{2}
  ]

### In Directed Graph

* **Indegree** = Number of incoming edges.
* **Outdegree** = Number of outgoing edges.

**Properties**

* Sum of indegrees = |E|
* Sum of outdegrees = |E|
* Maximum edges:
  [
  |V|(|V|-1)
  ]

---

## 4. Walk and Path

### Walk

* A sequence of vertices where vertices and edges **may repeat**.

Example:

```
V1 → V2 → V4 → V2
```

### Path (Simple Path)

* A walk where **no vertex repeats**.

Example:

```
V1 → V2 → V4
```

---

## 5. Cyclic and Acyclic Graph

### Cyclic Graph

* Contains at least one cycle.
* A path starts and ends at the same vertex.

### Acyclic Graph

* Contains **no cycles**.

### DAG (Directed Acyclic Graph)

* A directed graph with **no cycles**.
* Used in task scheduling, dependency resolution, etc.

---

## 6. Weighted and Unweighted Graph

### Weighted Graph

* Each edge has a numerical weight (cost, distance, time).

Example:

```
A ----10---- B
```

### Unweighted Graph

* Edges have no weights.
* Every edge is considered equal.

---

# Important Formulas

| Concept                 | Formula       |
| ----------------------- | ------------- |
| Graph                   | G = (V, E)    |
| Degree Sum (Undirected) | Σ Degree = 2E |
| Sum of Indegree         | |E|             |
| Sum of Outdegree        | |E|            |
| Max Edges (Undirected)  | V(V−1)/2      |
| Max Edges (Directed)    | V(V−1)        |

---

# Applications of Graphs

* Social Networks
* Google Maps & GPS Navigation
* Computer Networks
* Web Page Linking
* Airline Route Planning
* Recommendation Systems
* Dependency Management (DAG)

### Exam Tips

* **Directed Graph:** Edges have arrows.
* **Undirected Graph:** No arrows.
* **Degree:** Number of connected edges.
* **Indegree:** Incoming edges.
* **Outdegree:** Outgoing edges.
* **Walk:** Vertices may repeat.
* **Path:** No repeated vertices.
* **Cyclic:** Contains a cycle.
* **Acyclic:** No cycle.
* **Weighted:** Edges have weights.
* **Unweighted:** All edges are equal.
