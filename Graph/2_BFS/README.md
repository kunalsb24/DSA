# Breadth First Search (BFS) – Detailed Notes with Various Implementation Approaches (C++)

## What is BFS?

**Breadth First Search (BFS)** is a graph traversal algorithm that visits all vertices **level by level**. It starts from a source vertex and first visits all its immediate neighbors before moving to the next level.

* **Data Structure Used:** Queue (FIFO)
* **Traversal Order:** Level-wise

---

## BFS Algorithm

1. Mark the starting vertex as visited.
2. Insert the starting vertex into the queue.
3. Repeat until the queue is empty:

   * Remove the front vertex.
   * Visit (print/process) it.
   * Add all its unvisited adjacent vertices to the queue.
4. Continue until all reachable vertices are visited.

---

## Example

Graph:

```text
      0
     / \
    1   2
   / \   \
  3   4   5
```

Starting Vertex = **0**

Traversal Order:

```text
0 → 1 → 2 → 3 → 4 → 5
```

---

# Implementation Approaches

## Approach 1: BFS Using Adjacency List (Recommended)

### C++ Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // Remove for directed graph
    }

    void BFS(int start) {

        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << current << " ";

            for (int neighbor : adj[current]) {

                if (!visited[neighbor]) {

                    visited[neighbor] = true;
                    q.push(neighbor);

                }
            }
        }
    }
};

int main() {

    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);

    cout << "BFS Traversal: ";
    g.BFS(0);

    return 0;
}
```

### Output

```
BFS Traversal:
0 1 2 3 4 5
```

### Complexity

* Time: **O(V + E)**
* Space: **O(V)**

---

# Approach 2: BFS Using Adjacency Matrix

Suitable for **dense graphs**.

### C++ Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {

    int V = 6;

    int graph[6][6] = {

        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,0,1},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0}

    };

    bool visited[6] = {false};

    queue<int> q;

    int start = 0;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){

        int current = q.front();
        q.pop();

        cout << current << " ";

        for(int i=0;i<V;i++){

            if(graph[current][i]==1 && !visited[i]){

                visited[i]=true;
                q.push(i);

            }
        }
    }

    return 0;
}
```

### Output

```
0 1 2 3 4 5
```

### Complexity

* Time: **O(V²)**
* Space: **O(V²)**

---

# Approach 3: BFS Using STL Vector (Competitive Programming Style)

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100];

void BFS(int start, int V){

    vector<bool> visited(V,false);

    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(auto x:adj[node]){

            if(!visited[x]){

                visited[x]=true;
                q.push(x);

            }
        }
    }
}

int main(){

    int V=6;

    adj[0]={1,2};
    adj[1]={0,3,4};
    adj[2]={0,5};
    adj[3]={1};
    adj[4]={1};
    adj[5]={2};

    BFS(0,V);

    return 0;
}
```

---

# Approach 4: BFS for a Disconnected Graph

A single BFS only visits the connected component containing the starting vertex. To visit **all** vertices in a disconnected graph:

```cpp
void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited){

    queue<int> q;

    visited[start]=true;
    q.push(start);

    while(!q.empty()){

        int node=q.front();
        q.pop();

        cout<<node<<" ";

        for(int neighbor:adj[node]){

            if(!visited[neighbor]){

                visited[neighbor]=true;
                q.push(neighbor);

            }
        }
    }
}

int main(){

    int V=7;

    vector<vector<int>> adj(V);

    vector<bool> visited(V,false);

    // Add edges...

    for(int i=0;i<V;i++){

        if(!visited[i]){

            BFS(i,adj,visited);

        }
    }
}
```

This ensures **every connected component** is traversed.

---

# Comparison of BFS Implementations

| Approach               | Representation        | Time Complexity | Space Complexity | Best For                        |
| ---------------------- | --------------------- | --------------- | ---------------- | ------------------------------- |
| Adjacency List         | `vector<vector<int>>` | **O(V + E)**    | **O(V + E)**     | Sparse graphs                   |
| Adjacency Matrix       | 2D Array              | **O(V²)**       | **O(V²)**        | Dense graphs                    |
| STL Vector Array       | `vector<int> adj[]`   | **O(V + E)**    | **O(V + E)**     | Competitive programming         |
| Disconnected Graph BFS | Adjacency List        | **O(V + E)**    | **O(V)**         | Graphs with multiple components |

---

# Applications of BFS

* Shortest path in **unweighted graphs**
* Level-order traversal of binary trees
* Web crawling
* Social networking (friend suggestions)
* GPS navigation
* Network routing
* Finding connected components
* Broadcasting in computer networks

---

# Advantages

* Finds the shortest path in an unweighted graph.
* Visits vertices level by level.
* Easy to implement using a queue.
* Efficient for sparse graphs with adjacency lists.

---

# Disadvantages

* Requires extra memory for the queue and visited array.
* Less suitable than DFS for deep graph exploration.

---

# Exam Summary

* **BFS (Breadth First Search)** traverses a graph **level by level**.
* Uses a **Queue (FIFO)**.
* Marks vertices as visited to avoid revisiting.
* **Adjacency List implementation:** **O(V + E)** (recommended).
* **Adjacency Matrix implementation:** **O(V²)**.
* For **disconnected graphs**, run BFS from every unvisited vertex.
* Common applications include **shortest path in unweighted graphs**, **level-order traversal**, **network routing**, and **connected component detection**.
