// Practical : 01 - Implementation and Time analysis of sorting algorithms
// Name : Ravi Gohel | Roll No: 92510118030
// Date : 12/08/2026
// Objective : To implement Bubble Sort, Selection Sort, Insertion Sort, Merge Sort and Quick Sort
//             in C++ and analyse time complexity through execution-time measurements.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// ---------------- Bubble Sort ----------------
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// ---------------- Selection Sort ----------------
void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------- Merge Sort ----------------
void merge(vector<int> &arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size()) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < (int)left.size()) arr[k++] = left[i++];
    while (j < (int)right.size()) arr[k++] = right[j++];
}

void mergeSortHelper(vector<int> &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSort(vector<int> arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// ---------------- Quick Sort ----------------
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int> arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
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
    vector<int> sizes = {100, 1000, 5000, 10000};

    cout << "Size\tBubble\tSelection\tInsertion\tMerge\tQuick\t(all times in microseconds)\n";

    for (int n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;

        double tBubble = measureTime(bubbleSort, arr);
        double tSelection = measureTime(selectionSort, arr);
        double tInsertion = measureTime(insertionSort, arr);
        double tMerge = measureTime(mergeSort, arr);
        double tQuick = measureTime(quickSort, arr);

        cout << n << "\t" << tBubble << "\t" << tSelection << "\t\t"
             << tInsertion << "\t\t" << tMerge << "\t" << tQuick << "\n";
    }
    return 0;
}
