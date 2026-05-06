// ============================================================
//  Q1: Insertion Sort (with comparison count)
//  Compile: g++ -o q1 q1_insertion_sort.cpp
// ============================================================

#include <iostream>
using namespace std;

int main() {
    // ---------- Initialization ----------
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long comparisons = 0;

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    // ---------- Insertion Sort Logic ----------
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comparisons, arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    // ---------- Output ----------
    cout << "Sorted Array:   ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    cout << "Number of Comparisons: " << comparisons << "\n";

    return 0;
}
