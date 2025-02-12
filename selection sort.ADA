#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

void sortSelection(vector<int>& data) {
    int length = data.size();
    for (int i = 0; i < length - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < length; ++j) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
}

int main() {
    ofstream sizeFile("array_sizes.csv"), timeFile("sorting_times.csv");
    if (!sizeFile || !timeFile) {
        cerr << "Error opening files!";
        return 1;
    }

    for (int numElements = 3; numElements <= 25000; numElements *= 2) {
        vector<int> numbers(numElements);
        for (int i = 0; i < numElements; ++i) {
            numbers[i] = numElements - i;
        }

        clock_t begin = clock();
        for (int iter = 0; iter < 100; ++iter) {
            vector<int> temp = numbers;
            sortSelection(temp);
        }
        clock_t end = clock();
        double averageTime = double(end - begin) / (100 * CLOCKS_PER_SEC);

        sizeFile << numElements << ", ";
        timeFile << averageTime << ", ";
    }

    sizeFile.close();
    timeFile.close();
    cout << "Sorting process completed.";
    return 0;
}
