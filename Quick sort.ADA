#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int pivotPartition(vector<int>& nums, int left, int right) {
    int pivotValue = nums[left];
    int i = left, j = right;

    while (i < j) {
        while (i <= right && nums[i] <= pivotValue) ++i;
        while (j >= left && nums[j] > pivotValue) --j;
        if (i < j) swap(nums[i], nums[j]);
    }

    swap(nums[left], nums[j]);
    return j;
}

void recursiveQuickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pivotIndex = pivotPartition(nums, left, right);
        recursiveQuickSort(nums, left, pivotIndex - 1);
        recursiveQuickSort(nums, pivotIndex + 1, right);
    }
}

int main() {
    ofstream timeOutput("execution_time.csv"), sizeOutput("data_size.csv");
    if (!timeOutput || !sizeOutput) {
        cerr << "File error!";
        return 1;
    }

    for (int dataSize = 13; dataSize < 90000; dataSize = dataSize * log2(dataSize)) {
        vector<int> elements(dataSize);
        for (int i = 0; i < dataSize; ++i) {
            elements[i] = i;
        }

        clock_t begin = clock();
        for (int iter = 0; iter < 10; ++iter) {
            vector<int> temp = elements;
            recursiveQuickSort(temp, 0, dataSize - 1);
        }
        clock_t finish = clock();
        double avgTime = double(finish - begin) / (10 * CLOCKS_PER_SEC);
        
        timeOutput << avgTime << ", ";
        sizeOutput << dataSize << ", ";
        cout << dataSize << " ";
    }

    cout << "\nProcess completed";
    return 0;
}
