#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

/*
V : Number of vertices
For each vertext v, we can have V - 1 edges to consider.
From V vertices we can have V-1 edges.
*/
class Vertex {
    int index;
    int weight;
    int distance;
public :
    Vertex(int i, int w, int d) {
        index = i;
        weight = w;
        distance = d;
    }

};

class comparePair {
public :
    bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
        return (x.first > y.first);
    }
};

class Graph {
    int V;
    int E;
    vector<list<pair<int, int>>> adjList;

public :
    Graph(int V, int E) :
        V(V),
        E(E),
        adjList(V) {
    }

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    void dijkstra(int start) {
        vector<int> distance(V, INT_MAX);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comparePair> pq; // <distance, vertex>
        pq.push(make_pair(0,start));
        while (!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Remove all entries for same key(vertex)
            // by default priority_ques store in descending order so
            // remaing entry with same key should be neglected.


            for (auto i : adjList[u]) {
                int v = i.first;
                int weight = i.second;
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }

            }
            
        }

        for (int i = 0; i < distance.size(); i++) {
            cout << i << " : " << distance[i] << endl;
        }

    }
};

int main() {
    Graph g(4, 4);
    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 1, 1);
    g.dijkstra(0);
    return 0;
}