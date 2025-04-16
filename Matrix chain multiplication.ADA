#include <iostream>
#include <limits.h>
using namespace std;

int matrixChainOrder(int p[], int n) {
    int dp[n][n];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, n);
    return 0;
}
