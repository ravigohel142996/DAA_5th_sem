// Practical : 03 - Implementation and Time analysis of Max-Heap Sort algorithm
// Name : Ravi Gohel | Roll No: 92510118030
// Date : 12/08/2026
// Objective : To implement Max-Heap Sort in C++ (building a max-heap and repeatedly
//             extracting the maximum) and analyse its time complexity.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// ---------------- Max-Heapify ----------------
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// ---------------- Build Max-Heap ----------------
void buildMaxHeap(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// ---------------- Heap Sort ----------------
void heapSort(vector<int> arr) {
    int n = arr.size();
    buildMaxHeap(arr);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // move current max to the end
        heapify(arr, i, 0);     // restore heap property on the reduced heap
    }
}

// ---------------- Timing helper ----------------
template <typename Func>
double measureTime(Func f, vector<int> &arr) {
    auto start = high_resolution_clock::now();
    f(arr);
    auto stop = high_resolution_clock::now();
    return duration_cast<microseconds>(stop - start).count();
}

int main() {
    srand((unsigned)time(0));
    vector<int> sizes = {100, 1000, 5000, 10000, 50000, 100000};

    cout << "Size\tHeapSort(microseconds)\n";

    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000000;

        double tHeap = measureTime(heapSort, arr);
        cout << n << "\t" << tHeap << "\n";
    }
    return 0;
}
