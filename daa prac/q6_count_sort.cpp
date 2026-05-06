// ============================================================
//  Q6: Count Sort
//  Compile: g++ -o q6 q6_count_sort.cpp
// ============================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // ---------- Initialization ----------
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    // ---------- Count Sort Logic ----------
    int maxVal = *max_element(arr, arr + n);
    int minVal = *min_element(arr, arr + n);
    int range  = maxVal - minVal + 1;

    int count[range], output[n];
    fill(count, count + range, 0);

    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        output[--count[arr[i] - minVal]] = arr[i];

    // ---------- Output ----------
    cout << "Sorted Array:   ";
    for (int i = 0; i < n; i++) cout << output[i] << " ";
    cout << "\n";

    return 0;
}
