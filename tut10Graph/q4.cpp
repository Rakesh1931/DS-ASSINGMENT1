#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u,v,weight;
};

int findParent(vector<int>& parent, int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    x = findParent(parent,x);
    y = findParent(parent,y);
    if(rank[x]<rank[y]) parent[x]=y;
    else if(rank[x]>rank[y]) parent[y]=x;
    else { parent[y]=x; rank[x]++; }
}

bool cmp(Edge a, Edge b) { return a.weight < b.weight; }

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(V), rank(V,0);
    for(int i=0;i<V;i++) parent[i]=i;

    cout << "Edges in MST:\n";
    for(auto e: edges) {
        int u_set = findParent(parent,e.u);
        int v_set = findParent(parent,e.v);
        if(u_set != v_set) {
            cout << e.u << " - " << e.v << " : " << e.weight << endl;
            unionSets(parent,rank,u_set,v_set);
        }
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    kruskalMST(V, edges);
    return 0;
}
