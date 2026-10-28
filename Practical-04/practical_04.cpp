// Practical : 04 - Implementation and Time analysis of Factorial program
// Name : Ravi Gohel | Roll No: 92510118030
// Date : 12/08/2026
// Objective : To implement Factorial in C++ using both Iterative and Recursive methods
//             and analyse time complexity through execution-time measurements.

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

const long long MOD = 1000000007;  // keep results bounded for large n

// ---------------- Iterative Factorial ----------------
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result = (result * i) % MOD;
    return result;
}

// ---------------- Recursive Factorial ----------------
long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return (n * factorialRecursive(n - 1)) % MOD;
}

// ---------------- Timing helper ----------------
const int TRIALS = 2000; // repeat & average for a measurable, stable time

template <typename Func>
double measureAvgTime(Func f, int n) {
    volatile long long sink = 0;
    auto start = high_resolution_clock::now();
    for (int t = 0; t < TRIALS; t++)
        sink += f(n);
    auto stop = high_resolution_clock::now();
    (void)sink;
    return duration_cast<duration<double, micro>>(stop - start).count() / (double)TRIALS;
}

int main() {
    vector<int> sizes = {10, 100, 1000, 5000, 10000, 20000};

    cout << "n\tIterative(avg us)\tRecursive(avg us)\n";
    for (int n : sizes) {
        double tIter = measureAvgTime(factorialIterative, n);
        double tRec  = measureAvgTime(factorialRecursive, n);
        cout << n << "\t" << tIter << "\t\t" << tRec << "\n";
    }
    return 0;
}
