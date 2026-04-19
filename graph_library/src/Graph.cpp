#include "../include/Graph.hpp"

using namespace std;

Graph::Graph(int v) {
    vertices = v;
    adjList = new list<pair<int, int>>[v];
}

Graph::~Graph() {
    delete[] adjList;
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight}); 
}

void Graph::printGraph() {
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (auto node : adjList[i]) {
            cout << "(" << node.first << ", " << node.second << ") ";
        }
        cout << endl;
    }
}

void Graph::BFS(int start) {
    bool* visited = new bool[vertices];

    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (auto neighbor : adjList[v]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }

    delete[] visited;
    cout << endl;
}

void DFSUtil(int v, bool visited[], list<pair<int,int>>* adjList) {
    visited[v] = true;
    cout << v << " ";

    for (auto neighbor : adjList[v]) {
        if (!visited[neighbor.first]) {
            DFSUtil(neighbor.first, visited, adjList);
        }
    }
}

void Graph::DFS(int start) {
    bool* visited = new bool[vertices];

    for (int i = 0; i < vertices; i++)
        visited[i] = false;

    DFSUtil(start, visited, adjList);

    delete[] visited;
    cout << endl;
}

void Graph::shortestPath(int start) {
    int* dist = new int[vertices];

    for (int i = 0; i < vertices; i++)
        dist[i] = numeric_limits<int>::max();

    dist[start] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int current = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        for (auto neighbor : adjList[current]) {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (currentDist + weight < dist[next]) {
                dist[next] = currentDist + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "Shortest distances from " << start << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "To " << i << " = " << dist[i] << endl;
    }

    delete[] dist;
}
