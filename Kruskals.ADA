#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};


bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}


int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}


void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}


void kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compare); 
    vector<int> parent(V), rank(V, 0);
    
    for (int i = 0; i < V; i++) parent[i] = i; 

    vector<Edge> result;
    int cost = 0;

    for (Edge e : edges) {
        if (findParent(e.src, parent) != findParent(e.dest, parent)) {
            result.push_back(e);
            cost += e.weight;
            unionSets(e.src, e.dest, parent, rank);
        }
    }

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (Edge e : result)
        cout << e.src << " - " << e.dest << " : " << e.weight << endl;
    
    cout << "Total MST Cost: " << cost << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

    kruskalMST(edges, V);
    return 0;
}
