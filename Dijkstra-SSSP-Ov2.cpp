#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

/*
V : Number of vertices
For each vertext v, we can have V - 1 edges to consider.
From V vertices we can have V-1 edges.
*/

class Graph {
    int V;
    int E;
    vector<list<int>> adjList;

public :
    Graph(int V, int E) :
        V(V),
        E(E),
        adjList(V) {
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    int miniumDistance(vector<bool>& visited, vector<int>& distance) {
        int min = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                min_index = i;
            }
        }
        return min_index;
    }

    void dijkstra(int start, int g[][4]) {
        vector<bool> visited(V, false);
        vector<int> distance(V, INT_MAX);
        distance[start] = 0;

        // Choose from number of edges
        // For V vertices spanning tree has (V-1) edges.
        for (int e = 0; e < V - 1; e++) {
            int u = miniumDistance(visited, distance);
            visited[u] = true;
            for (int v = 0; v < V; v++) {
                if (!visited[v]
                    && g[u][v]
                    && distance[u] != INT_MAX
                    && distance[v] > distance[u] + g[u][v]) {
                    distance[v] = distance[u] + g[u][v];
                }
            }
        }

        cout << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " : " << distance[i] << endl;
        }
    }
};

int main() {
    int graph[4][4] = {
        { 0, 3, 1, 0},
        { 0, 0, 0, 5},
        { 0, 0, 0, 2},
        { 0, 0, 0, 0}
    };

    Graph g(4, 4);
    g.dijkstra(0, graph);
    return 0;
}