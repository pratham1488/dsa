#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef vector<vector<int>> Matrix;

Matrix add(Matrix& A, Matrix& B, int n) {
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix sub(Matrix& A, Matrix& B, int n) {
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix multiply(Matrix& A, Matrix& B, int n) {
    if (n == 1) return {{A[0][0] * B[0][0]}};
    
    int m = n / 2;
    Matrix A11(m, vector<int>(m)), A12(m, vector<int>(m)), A21(m, vector<int>(m)), A22(m, vector<int>(m));
    Matrix B11(m, vector<int>(m)), B12(m, vector<int>(m)), B21(m, vector<int>(m)), B22(m, vector<int>(m));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            A11[i][j] = A[i][j], A12[i][j] = A[i][j + m];
            A21[i][j] = A[i + m][j], A22[i][j] = A[i + m][j + m];
            B11[i][j] = B[i][j], B12[i][j] = B[i][j + m];
            B21[i][j] = B[i + m][j], B22[i][j] = B[i + m][j + m];
        }

    Matrix P = multiply(add(A11, A22, m), add(B11, B22, m), m);
    Matrix Q = multiply(add(A21, A22, m), B11, m);
    Matrix R = multiply(A11, sub(B12, B22, m), m);
    Matrix S = multiply(A22, sub(B21, B11, m), m);
    Matrix T = multiply(add(A11, A12, m), B22, m);
    Matrix U = multiply(sub(A21, A11, m), add(B11, B12, m), m);
    Matrix V = multiply(sub(A12, A22, m), add(B21, B22, m), m);

    Matrix C(n, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            C[i][j] = P[i][j] + S[i][j] - T[i][j] + V[i][j];
            C[i][j + m] = R[i][j] + T[i][j];
            C[i + m][j] = Q[i][j] + S[i][j];
            C[i + m][j + m] = P[i][j] + R[i][j] - Q[i][j] + U[i][j];
        }
    
    return C;
}

void printMatrix(Matrix& mat) {
    for (auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;

    srand(time(0));
    Matrix A(n, vector<int>(n)), B(n, vector<int>(n));
    for (auto& row : A) for (int& val : row) val = rand() % 10;
    for (auto& row : B) for (int& val : row) val = rand() % 10;

    cout << "\nMatrix A:\n"; printMatrix(A);
    cout << "\nMatrix B:\n"; printMatrix(B);
    
    Matrix C = multiply(A, B, n);
    
    cout << "\nResult Matrix:\n"; printMatrix(C);
    
    return 0;
}
