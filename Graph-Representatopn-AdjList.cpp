#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    int E;
    list<int>* adjList;
public :
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        this->adjList = new list<int>[V];
    }

    void addEdge(int src, int dest) {
        this->adjList[src].push_back(dest);
        //this->adjList[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << "\t[";
            for (int v : adjList[i]) {
                cout << v << ", ";
            }
            cout << "]" << endl;
        }
    }

    ~Graph() {
        delete[] this->adjList;
    }
};

int main() {
    Graph g(6, 7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 4);

    g.printGraph();
    return 0;
}
