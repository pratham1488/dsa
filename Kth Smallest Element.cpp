#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1)
            return arr[pivotIndex];
        else if (pivotIndex > k - 1) // Look in the left part
            return quickSelect(arr, low, pivotIndex - 1, k);
        else // Look in the right part
            return quickSelect(arr, pivotIndex + 1, high, k);
    }
    return -1; // Should never reach here
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3; 

    int n = arr.size();
    if (k > 0 && k <= n) {
        int result = quickSelect(arr, 0, n - 1, k);
        cout << "The " << k << "rd smallest element is: " << result << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }

    return 0;
}
