#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight=1) {
        adj[u][v] = weight;
        adj[v][u] = weight; // comment this line if graph is directed
    }

    void displayMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    void adjacentVertices(int v) {
        cout << "Adjacent vertices of " << v << ": ";
        for (int i = 0; i < V; i++) {
            if (adj[v][i] != 0) cout << i << " ";
        }
        cout << endl;
    }

    int degree(int v) {
        int deg = 0;
        for (int i = 0; i < V; i++)
            if (adj[v][i] != 0) deg++;
        return deg;
    }

    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < V; i++)
            for (int j = i; j < V; j++)
                if (adj[i][j] != 0) count++;
        return count;
    }
};

int main() {
    Graph g(5); // 5 vertices

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.displayMatrix();
    g.adjacentVertices(1);
    cout << "Degree of vertex 1: " << g.degree(1) << endl;
    cout << "Number of edges: " << g.numberOfEdges() << endl;

    return 0;
}
