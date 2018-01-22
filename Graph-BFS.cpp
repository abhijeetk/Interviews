#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    int E;
    vector<list<int>> adjList;

    void BFSUtil(int start) {
    
    }
public :
    Graph(int V, int E) :
        V(V),
        E(E),
        adjList(V) {
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " -> ";

            for (int i : adjList[vertex]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }

            }
        }
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

    g.BFS(2);
    return 0;
}