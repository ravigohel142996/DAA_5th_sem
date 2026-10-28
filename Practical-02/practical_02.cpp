// Practical : 02 - Implementation and Time analysis of Linear Search and Binary Search
// Name : Ravi Gohel | Roll No: 92510118030
// Date : 12/08/2026
// Objective : To implement Linear Search and Binary Search in C++ and analyse time complexity
//             through execution-time measurements on inputs of varying size.

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// ---------------- Linear Search ----------------
int linearSearch(const vector<int>& arr, int key)
{
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// ---------------- Binary Search ----------------
int binarySearch(const vector<int>& arr, int key)
{
    int low = 0;
    int high = (int)arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Number of trials for timing
const int TRIALS = 5000;

// ---------------- Measure Average Time ----------------
template <typename Func>
double measureAvgTime(Func f, const vector<int>& arr, int key)
{
    volatile int sink = 0;
    auto start = high_resolution_clock::now();
    for (int t = 0; t < TRIALS; t++)
    {
        sink += f(arr, key);
    }
    auto stop = high_resolution_clock::now();
    (void)sink;
    return duration_cast<microseconds>(stop - start).count()
           / (double)TRIALS;
}

// ---------------- Main Function ----------------
int main()
{
    vector<int> sizes = {100, 1000, 5000, 10000, 50000, 100000};

    cout << "Size\tLinear(worst)\tBinary(worst)"
         << "\t(avg of " << TRIALS << " runs, microseconds)\n";

    for (int n : sizes)
    {
        vector<int> arr(n);
        // Sorted array of even numbers
        for (int i = 0; i < n; i++)
        {
            arr[i] = i * 2;
        }

        // Absent value -> worst case for both algorithms
        int key = -1;

        double tLinear = measureAvgTime(linearSearch, arr, key);
        double tBinary = measureAvgTime(binarySearch, arr, key);

        cout << n << "\t"
             << tLinear << "\t\t"
             << tBinary << "\n";
    }
    return 0;
}
