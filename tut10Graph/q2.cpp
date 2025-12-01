#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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

    BFS(adj, 0);
    return 0;
}
