// Practical : 05 - Implementation of 0/1 Knapsack Problem using Dynamic Programming
// Name : Ravi Gohel | Roll No: 92510118030
// Date : 12/08/2026
// Objective : To implement 0/1 Knapsack using DP to determine maximum value
//             achievable within a given weight capacity.

#include <iostream>
#include <vector>
using namespace std;

// ---------------- 0/1 Knapsack (Dynamic Programming, O(nW)) ----------------
int knapsack01(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w]; // exclude item i
            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120, 80};
    vector<int> wt  = {10, 20, 30, 15};
    int W = 50;
    int n = val.size();

    int best = knapsack01(W, wt, val, n);
    cout << "Maximum value in knapsack of capacity " << W << ": " << best << endl;
    return 0;
}
