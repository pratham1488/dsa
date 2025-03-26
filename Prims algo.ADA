#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX


int minKey(vector<int>& key, vector<bool>& inMST, int V) {
    int minIndex = -1, minValue = INF;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minValue) {
            minValue = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}


void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);  
    vector<int> key(V, INF);   
    vector<bool> inMST(V, false); 

    key[0] = 0; // Start from node 0

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V); 
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter adjacency matrix (0 for no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}
