#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int>& dist, vector<bool>& sptSet) {
    int min = INT_MAX, min_index;
    for(int v=0;v<dist.size();v++)
        if(!sptSet[v] && dist[v]<=min) { min=dist[v]; min_index=v; }
    return min_index;
}

void dijkstra(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V,false);

    dist[src]=0;

    for(int count=0; count<V-1; count++) {
        int u = minDistance(dist,sptSet);
        sptSet[u]=true;

        for(int v=0;v<V;v++)
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
                dist[v]=dist[u]+graph[u][v];
    }

    cout << "Vertex Distance from Source " << src << ":\n";
    for(int i=0;i<V;i++)
        cout << i << " : " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 0, 0, 0, 8},
        {10,0,10,0,0,0,0,0},
        {0,10,0,12,0,0,0,0},
        {0,0,12,0,8,0,0,0},
        {0,0,0,8,0,7,0,4},
        {0,0,0,0,7,0,5,0},
        {0,0,0,0,0,5,0,6},
        {8,0,0,0,4,0,6,0}
    };
    dijkstra(graph, 0);
    return 0;
}
