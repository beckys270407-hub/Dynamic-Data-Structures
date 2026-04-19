#include "../include/Graph.hpp"

using namespace std;

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(3, 4, 4);

    cout << "Graph:\n";
    g.printGraph();

    cout << "\nBFS: ";
    g.BFS(0);

    cout << "DFS: ";
    g.DFS(0);

    cout << "\nDijkstra:\n";
    g.shortestPath(0);

    return 0;
}
