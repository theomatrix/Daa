//DAA Practicals — Individual Full Programs (Copy-Paste Ready)

//Each section below is a complete standalone C++ program with its own main() function, so you can directly copy any one block into a new .cpp file and run it independently.


---

//1. Insertion Sort (with Comparison Count)

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


---

//2. Merge Sort (with Comparison Count)

#include <iostream>
#include <vector>
using namespace std;

long long mergeCount = 0;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;

    while (i < left.size() && j < right.size()) {
        mergeCount++;
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    printArray(arr);
    cout << "Comparisons: " << mergeCount << endl;

    return 0;
}


---

//3. Heap Sort (with Comparison Count)

#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        comparisons++;
        if (arr[l] > arr[largest]) largest = l;
    }

    if (r < n) {
        comparisons++;
        if (arr[r] > arr[largest]) largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}


---

//4. Quick Sort (with Comparison Count)

#include <iostream>
#include <vector>
using namespace std;

long long comparisons = 0;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    printArray(arr);
    cout << "Comparisons: " << comparisons << endl;

    return 0;
}


---

//5. Strassen’s Matrix Multiplication (2x2)

#include <iostream>
using namespace std;

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
    int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];

    int P1 = a * (f - h);
    int P2 = (a + b) * h;
    int P3 = (c + d) * e;
    int P4 = d * (g - e);
    int P5 = (a + d) * (e + h);
    int P6 = (b - d) * (g + h);
    int P7 = (a - c) * (e + f);

    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P5 + P1 - P3 - P7;
}

int main() {
    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};
    int C[2][2];

    strassenMultiply(A, B, C);

    cout << "Result Matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}


---

//6. Count Sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

void countSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    for (int x : arr) count[x - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
        output[--count[arr[i] - minVal]] = arr[i];

    arr = output;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    countSort(arr);

    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}


---

//7. BFS (Breadth First Search)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0,1); addEdge(0,2);
    addEdge(1,3); addEdge(1,4);
    addEdge(3,5);

    cout << "BFS Traversal: ";
    bfs(adj, 0);

    return 0;
}


---

//8. DFS (Depth First Search)

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
        if (!visited[neighbor])
            dfs(adj, neighbor, visited);
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0,1); addEdge(0,2);
    addEdge(1,3); addEdge(1,4);
    addEdge(3,5);

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(adj, 0, visited);

    return 0;
}


---

//9. Prim’s Minimum Spanning Tree

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void primMST(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> inMST(n, false);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u]))
                u = v;

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    primMST(graph);

    return 0;
}


---

//10. Dijkstra’s Shortest Path

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u]))
                u = v;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest Distances from Source:\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    dijkstra(graph, 0);

    return 0;
}


---

//11. 0-1 Knapsack (Dynamic Programming)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {1, 2, 3};
    int capacity = 5;
    int n = values.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w],
                               dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    cout << "Maximum Value: " << dp[n][capacity] << endl;

    cout << "Selected Items (1-indexed): ";
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weights[i - 1];
        }
    }

    return 0;
}
