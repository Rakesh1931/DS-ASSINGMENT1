#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(vector<vector<int>>& adj, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < adj.size(); i++)
        if (adj[v][i] != 0 && !visited[i])
            DFSUtil(adj, i, visited);
}

void DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    cout << "DFS: ";
    DFSUtil(adj, start, visited);
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V, vector<int>(V,0));

    adj[0][1]=1; adj[0][4]=1;
    adj[1][0]=1; adj[1][2]=1; adj[1][3]=1; adj[1][4]=1;
    adj[2][1]=1; adj[2][3]=1;
    adj[3][1]=1; adj[3][2]=1; adj[3][4]=1;
    adj[4][0]=1; adj[4][1]=1; adj[4][3]=1;

    DFS(adj, 0);
    return 0;
}
