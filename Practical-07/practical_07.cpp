// Practical : 07 - Implementation of Making Change problem using DP
// Name : Ravi Gohel | Enrolment No: 92510118030
// Objective : To implement Coin Change / Making Change using Dynamic Programming
//             to find minimum number of coins required to make a given amount.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum coins required to make amount i
    vector<int> dp(amount + 1, INT_MAX);

    // 0 coins are required to make amount 0
    dp[0] = 0;

    // Calculate minimum coins for each amount
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
    {
        cout << "Change cannot be made for the given amount." << endl;
    }
    else
    {
        cout << "Minimum number of coins required: "
             << dp[amount] << endl;
    }
    return 0;
}
