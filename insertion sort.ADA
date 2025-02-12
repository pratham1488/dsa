#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std::chrono;
using namespace std;

void customSort(vector<int>& data, int length) {
    for (int idx = 1; idx < length; ++idx) {
        int temp = data[idx];
        int pos = idx - 1;
        while (pos >= 0 && data[pos] > temp) {
            data[pos + 1] = data[pos];
            --pos;
        }
        data[pos + 1] = temp;
    }
}

int main() {
    ofstream fileOut("sizes.csv"), timeOut("times.csv");
    if (!fileOut || !timeOut) {
        cerr << "File opening failed!";
        return 1;
    }

    for (int size = 2; size <= 25000; size *= 2) {
        vector<int> values(size);
        for (int idx = 0; idx < size; ++idx) {
            values[idx] = rand() % 10000;
        }

        auto startTime = high_resolution_clock::now();
        for (int iter = 0; iter < 100; ++iter) {
            vector<int> tempData = values;
            customSort(tempData, size);
        }
        auto endTime = high_resolution_clock::now();

        auto elapsed = duration_cast<nanoseconds>(endTime - startTime) / 100;
        fileOut << size << ", ";
        timeOut << elapsed.count() << ", ";
    }

    fileOut.close();
    timeOut.close();
    cout << "Task completed.";
}
