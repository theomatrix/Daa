#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

long long insertionSort(vector<int>& arr) {
    long long comparisons = 0;
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && (++comparisons, arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    long long comparisons = insertionSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}
