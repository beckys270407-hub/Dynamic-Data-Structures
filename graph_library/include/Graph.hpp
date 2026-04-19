#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <list>
#include <queue>
#include <limits>

using namespace std;

class Graph {
private:
    int vertices;
    list<pair<int, int>>* adjList; 

public:
    Graph(int v);
    ~Graph();

    void addEdge(int u, int v, int weight = 1);
    void printGraph();

    void BFS(int start);
    void DFS(int start);

    void shortestPath(int start); 
};

#endif
