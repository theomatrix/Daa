/*
 * ============================================================
 *        DAA Practical List - Ramanujan College, DU
 *        All 11 Programs | Semester IV - B.Sc (H) CS
 * ============================================================
 *
 *  Programs included:
 *   1.  Insertion Sort  (comparison count)
 *   2.  Merge Sort      (comparison count)
 *   3.  Heap Sort       (comparison count)
 *   4.  Quick Sort      (comparison count)
 *   5.  Strassen's Matrix Multiplication (2x2)
 *   6.  Count Sort
 *   7.  BFS on a Graph
 *   8.  DFS on a Graph
 *   9.  Prim's MST
 *  10.  Dijkstra's Shortest Path
 *  11.  0-1 Knapsack (Dynamic Programming)
 *
 * ============================================================
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

// ─────────────────────────────────────────────────────────
//  Utility: print array
// ─────────────────────────────────────────────────────────
void printArray(const vector<int>& arr, const string& label = "") {
    if (!label.empty()) cout << label << ": ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

// ============================================================
//  QUESTION 1: Insertion Sort (with comparison count)
// ============================================================
long long insertionSort(vector<int> arr) {
    int n = arr.size();
    long long comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && (++comparisons, arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printArray(arr, "Insertion Sorted");
    return comparisons;
}

// ============================================================
//  QUESTION 2: Merge Sort (with comparison count)
// ============================================================
long long mergeCount = 0;

void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size()) {
        mergeCount++;
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else                      arr[k++] = right[j++];
    }
    while (i < (int)left.size())  arr[k++] = left[i++];
    while (j < (int)right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    merge(arr, l, m, r);
}

long long mergeSort(vector<int> arr) {
    mergeCount = 0;
    mergeSortHelper(arr, 0, (int)arr.size() - 1);
    printArray(arr, "Merge Sorted");
    return mergeCount;
}

// ============================================================
//  QUESTION 3: Heap Sort (with comparison count)
// ============================================================
long long heapComparisons = 0;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) { heapComparisons++; if (arr[l] > arr[largest]) largest = l; }
    if (r < n) { heapComparisons++; if (arr[r] > arr[largest]) largest = r; }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

long long heapSort(vector<int> arr) {
    heapComparisons = 0;
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    printArray(arr, "Heap Sorted");
    return heapComparisons;
}

// ============================================================
//  QUESTION 4: Quick Sort (with comparison count)
// ============================================================
long long quickComparisons = 0;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        quickComparisons++;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

long long quickSort(vector<int> arr) {
    quickComparisons = 0;
    quickSortHelper(arr, 0, (int)arr.size() - 1);
    printArray(arr, "Quick Sorted");
    return quickComparisons;
}

// ============================================================
//  QUESTION 5: Strassen's Matrix Multiplication (2x2)
// ============================================================
void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
    int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];

    // Strassen's 7 products
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

void runStrassen() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2] = {};

    strassenMultiply(A, B, C);

    cout << "Strassen Result (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
}

// ============================================================
//  QUESTION 6: Count Sort
// ============================================================
void countSort(vector<int> arr) {
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range  = maxVal - minVal + 1;

    vector<int> count(range, 0), output(arr.size());

    for (int x : arr)       count[x - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = (int)arr.size() - 1; i >= 0; i--)
        output[--count[arr[i] - minVal]] = arr[i];

    printArray(output, "Count Sorted");
}

// ============================================================
//  QUESTION 7: BFS on a Graph
// ============================================================
void bfs(const vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS traversal from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "\n";
}

// ============================================================
//  QUESTION 8: DFS on a Graph
// ============================================================
void dfsUtil(const vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node])
        if (!visited[neighbor])
            dfsUtil(adj, neighbor, visited);
}

void dfs(const vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false);
    cout << "DFS traversal from node " << start << ": ";
    dfsUtil(adj, start, visited);
    cout << "\n";
}

// ============================================================
//  QUESTION 9: Prim's MST (Adjacency Matrix)
// ============================================================
void primMST(const vector<vector<int>>& graph, int n) {
    vector<int> key(n, INT_MAX);   // Min edge weight to include vertex
    vector<int> parent(n, -1);     // MST parent array
    vector<bool> inMST(n, false);

    key[0] = 0;

    for (int iter = 0; iter < n - 1; iter++) {
        // Pick minimum key vertex not yet in MST
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST Edges (Edge : Weight):\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << "  " << parent[i] << " -- " << i
             << "  :  " << graph[parent[i]][i] << "\n";
        totalWeight += graph[parent[i]][i];
    }
    cout << "Total MST Weight: " << totalWeight << "\n";
}

// ============================================================
//  QUESTION 10: Dijkstra's Shortest Path (Adjacency Matrix)
// ============================================================
void dijkstra(const vector<vector<int>>& graph, int src, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int iter = 0; iter < n - 1; iter++) {
        // Pick unvisited vertex with minimum distance
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;

        if (dist[u] == INT_MAX) break;
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Dijkstra's Shortest Distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  Node " << i << "  :  ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else                    cout << dist[i] << "\n";
    }
}

// ============================================================
//  QUESTION 11: 0-1 Knapsack using Dynamic Programming
// ============================================================
void knapsack01(const vector<int>& weights, const vector<int>& values,
                int capacity, int n) {
    // dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w]; // Don't include item i
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i][w],
                               dp[i - 1][w - weights[i - 1]] + values[i - 1]);
        }
    }

    cout << "0-1 Knapsack Max Value: " << dp[n][capacity] << "\n";

    // Backtrack to find selected items
    cout << "Selected items (1-indexed): ";
    int w = capacity;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weights[i - 1];
        }
    }
    cout << "\n";
}

// ============================================================
//                          MAIN
// ============================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "============================================================\n";
    cout << "         DAA Practical List - All 11 Programs\n";
    cout << "============================================================\n\n";

    // ──────────────────────────────────────────────────────────────────
    vector<int> arr = {64, 25, 12, 22, 11};
    printArray(arr, "Original Array");
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q1: Insertion Sort\n";
    cout << "------------------------------------------------------------\n";
    long long c1 = insertionSort(arr);
    cout << "Number of comparisons: " << c1 << "\n\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q2: Merge Sort\n";
    cout << "------------------------------------------------------------\n";
    long long c2 = mergeSort(arr);
    cout << "Number of comparisons: " << c2 << "\n\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q3: Heap Sort\n";
    cout << "------------------------------------------------------------\n";
    long long c3 = heapSort(arr);
    cout << "Number of comparisons: " << c3 << "\n\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q4: Quick Sort\n";
    cout << "------------------------------------------------------------\n";
    long long c4 = quickSort(arr);
    cout << "Number of comparisons: " << c4 << "\n\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q5: Strassen's 2x2 Matrix Multiplication\n";
    cout << "------------------------------------------------------------\n";
    runStrassen();
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q6: Count Sort\n";
    cout << "------------------------------------------------------------\n";
    countSort(arr);
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    // Graph for Q7 and Q8 (Adjacency List, 6 nodes)
    //  0 -- 1 -- 3
    //  |    |    |
    //  2    4    5
    int graphNodes = 6;
    vector<vector<int>> adjList(graphNodes);
    auto addEdge = [&](int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    };
    addEdge(0, 1); addEdge(0, 2);
    addEdge(1, 3); addEdge(1, 4);
    addEdge(3, 5);

    cout << "------------------------------------------------------------\n";
    cout << "  Q7: Breadth-First Search (BFS)\n";
    cout << "------------------------------------------------------------\n";
    bfs(adjList, 0, graphNodes);
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q8: Depth-First Search (DFS)\n";
    cout << "------------------------------------------------------------\n";
    dfs(adjList, 0, graphNodes);
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    // Weighted graph for Q9 and Q10 (Adjacency Matrix, 5 nodes)
    int wn = 5;
    vector<vector<int>> wGraph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    cout << "------------------------------------------------------------\n";
    cout << "  Q9: Prim's Minimum Spanning Tree\n";
    cout << "------------------------------------------------------------\n";
    primMST(wGraph, wn);
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q10: Dijkstra's Shortest Path (source = 0)\n";
    cout << "------------------------------------------------------------\n";
    dijkstra(wGraph, 0, wn);
    cout << "\n";

    // ──────────────────────────────────────────────────────────────────
    cout << "------------------------------------------------------------\n";
    cout << "  Q11: 0-1 Knapsack using Dynamic Programming\n";
    cout << "------------------------------------------------------------\n";
    vector<int> values  = {60, 100, 120};
    vector<int> weights = { 1,   2,   3};
    int capacity = 5, n = 3;
    cout << "Items (value, weight): ";
    for (int i = 0; i < n; i++)
        cout << "(" << values[i] << "," << weights[i] << ") ";
    cout << "\nKnapsack Capacity: " << capacity << "\n";
    knapsack01(weights, values, capacity, n);
    cout << "\n";

    cout << "============================================================\n";
    cout << "              End of DAA Practical List\n";
    cout << "============================================================\n";

    return 0;
}
