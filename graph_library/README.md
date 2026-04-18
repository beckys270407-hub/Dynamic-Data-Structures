# GRAPH MINI LIBRARY (C++)

## 📌 DESCRIPTION

This project implements a simple graph library using adjacency lists and dynamic memory.
It allows easy creation and manipulation of graphs, including traversal algorithms and shortest path calculation.

The library is designed for educational purposes, focusing on dynamic data structures in C++.

---

## 📁 PROJECT STRUCTURE

graph_library/
│
├── include/ → Header files (Graph.hpp)
├── src/ → Implementation files (Graph.cpp)
├── examples/ → Example usage (main.cpp)
└── README.md → Documentation

---

## ⚙️ FEATURES

* Graph representation using adjacency lists
* Dynamic memory management (no use of vector)
* Breadth-First Search (BFS)
* Depth-First Search (DFS)
* Shortest path using Dijkstra's algorithm (priority queue)

---

## 🧠 FUNCTIONS

### Graph(int v)

Creates a graph with `v` vertices.

### addEdge(int u, int v, int weight)

Adds an edge between vertices `u` and `v` with a given weight.

### printGraph()

Displays the adjacency list of the graph.

### BFS(int start)

Performs Breadth-First Search starting from a given node.

### DFS(int start)

Performs Depth-First Search starting from a given node.

### shortestPath(int start)

Calculates the shortest paths from a starting node using Dijkstra's algorithm.

---

## 🛠️ COMPILATION INSTRUCTIONS

Make sure you are inside the root folder:

```
cd graph_library
```

### ✅ Compile the program:

```
g++ src/Graph.cpp examples/main.cpp -Iinclude -o graph_program
```

### ▶️ Run the program (PowerShell / Windows):

```
.\graph_program.exe
```

### ▶️ Run on Linux / Mac:

```
./graph_program
```

---

## ⚠️ IMPORTANT NOTES

* PowerShell requires `.\` before running executables in the current directory.
* The graph is **undirected**.
* The implementation uses **dynamic memory (new/delete)** instead of vectors.
* Dijkstra's algorithm is implemented using a **priority queue**.

---

## 🎯 PURPOSE

This library was developed to demonstrate:

* Use of dynamic data structures
* Implementation of graph algorithms
* Modular programming with header and source files

---

## 📌 EXAMPLE OUTPUT

Graph:
0: (1, 2) (4, 1)
1: (0, 2) (2, 3) (3, 2)
2: (1, 3)
3: (1, 2) (4, 4)
4: (0, 1) (3, 4)

BFS: 0 1 4 2 3
DFS: 0 1 2 3 4

Dijkstra:
Shortest distances from 0:
To 0 = 0
To 1 = 2
To 2 = 5
To 3 = 4
To 4 = 1

---

## ✅ CONCLUSION

The library successfully implements graph structures and algorithms using dynamic memory.
All functions behave as expected and match the documented behavior.

---

