#include <iostream>
#include <list>
#include <vector>
#include <stack>
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

    void DFSUtilIterative(int startVertex, vector<bool>& visited) {
        stack<int> s;
        s.push(startVertex);
        visited[startVertex] = true;

        while (!s.empty()) {
            int st = s.top();
            cout << st << " -> ";
            s.pop();

            for (int i : adjList[st]) {
                if (!visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
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

    void DFSIterative(int start) {
        vector<bool> visited(V, false);
        DFSUtilIterative(start, visited);
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
    cout << endl;
    g.DFS(2);
    cout << endl;
    g.DFSIterative(2);

    Graph g1(5, 5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(1, 4);
    cout << endl;
    g1.DFS(0);
    cout << endl;
    g1.DFSIterative(0);

    return 0;
}
