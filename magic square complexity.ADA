#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std::chrono;
using namespace std;

void generateMagicSquare(vector<vector<int>>& grid, int size) {
    for (auto& row : grid) {
        fill(row.begin(), row.end(), 0);
    }

    int r = 0, c = size / 2;
    for (int num = 1; num <= size * size; ++num) {
        grid[r][c] = num;
        int new_r = (r - 1 + size) % size;
        int new_c = (c - 1 + size) % size;
        
        if (grid[new_r][new_c] != 0) {
            r = (r + 1) % size;
        } else {
            r = new_r;
            c = new_c;
        }
    }
}

int main() {
    ofstream timeFile("time_data.csv"), sizeFile("size_data.csv");
    if (!timeFile || !sizeFile) {
        cerr << "Error opening files!";
        return 1;
    }

    for (int dim = 2; dim <= 25000; dim *= 2) {
        int matrixSize = dim + 1;
        vector<vector<int>> square(matrixSize, vector<int>(matrixSize));

        auto startTime = high_resolution_clock::now();
        for (int repeat = 0; repeat < 5; ++repeat) {
            generateMagicSquare(square, matrixSize);
        }
        auto endTime = high_resolution_clock::now();
        auto elapsed = duration_cast<microseconds>(endTime - startTime) / 5;
        
        timeFile << elapsed.count() << ", ";
        sizeFile << matrixSize << ", ";
    }

    timeFile.close();
    sizeFile.close();
    return 0;
}
