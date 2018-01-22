#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    int E;
    vector<list<int>> adjList;

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " -> ";
        for (auto i : adjList[vertex]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    
    }

public :
    Graph(int V, int E) : V(V), E(E), adjList(V) {
    }

    void addEdge(int src, int dest) {
       adjList[src].push_back(dest);
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(4, 6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);
    return 0;
}
