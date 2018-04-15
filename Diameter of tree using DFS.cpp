#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;
    int E;
    vector<list<int>> adjList;

public:
    int longestNode = -1;
    Graph(int V, int E) :
        V(V),
        E(E),
        adjList(V) {
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void DFS(int start, vector<bool>& visited, int depth, int& maxDepth) {
        visited[start] = true;
        depth++;
        for (auto itr : adjList[start]) {
            if (!visited[itr]) {
                if (depth > maxDepth) {
                    maxDepth = depth;
                    longestNode = itr;
                    //cout << itr << " - " << depth << endl;
                }
                DFS(itr, visited, depth, maxDepth);
            }
        }
    }

    void DFSUtil(int start, int& maxDepth) {
        vector<bool> visited(V, false);
        int depth = 0;
        DFS(start, visited, depth, maxDepth);
        //cout << "MaxDepth = " << maxDepth << endl;

    }
};

int main() {
/*
    Constructed binary tree is
           1
         /  \
        2    3
       /  \
      4    5
*/
    Graph g(6, 0);   // max vertex number is 5 so vector size should be 6
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 1);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 2);
    int maxDepth = 0;
    g.DFSUtil(2, maxDepth);
    cout << "Finding farthest node ..." << endl;
    g.DFSUtil(g.longestNode, maxDepth);
    cout << "Diameter is : " << maxDepth + 1 << endl;


    return 0;
}