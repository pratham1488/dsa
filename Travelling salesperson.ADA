#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(vector<vector<int>> &graph, vector<bool> &visited, int pos, int n, int count, int cost, int start) {
    if (count == n && graph[pos][start])
        return cost + graph[pos][start];
    
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true;
            int temp = tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start);
            ans = min(ans, temp);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    int result = tsp(graph, visited, 0, n, 1, 0, 0);
    cout << "Minimum cost: " << result << endl;
    return 0;
}
