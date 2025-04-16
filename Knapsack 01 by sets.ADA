#include <iostream>
#include <set>
using namespace std;

int knapsack(int weights[], int values[], int n, int capacity) {
    set<pair<int, int>> s;
    s.insert({0, 0});
    for (int i = 0; i < n; i++) {
        set<pair<int, int>> temp(s);
        for (auto it : s) {
            int new_wt = it.first + weights[i];
            int new_val = it.second + values[i];
            if (new_wt <= capacity) {
                temp.insert({new_wt, new_val});
            }
        }
        s = temp;
    }
    int max_val = 0;
    for (auto it : s) {
        if (it.first <= capacity) {
            max_val = max(max_val, it.second);
        }
    }
    return max_val;
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 6};
    int n = 4;
    int capacity = 5;
    int max_value = knapsack(weights, values, n, capacity);
    cout << "Maximum value in Knapsack = " << max_value << endl;
    return 0;
}
