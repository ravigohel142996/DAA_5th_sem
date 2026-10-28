// Practical : 06 - Implementation of Matrix Chain Multiplication using DP
// Name : Ravi Gohel | Enrolment No: 92510118030
// Objective : To implement Matrix Chain Multiplication using Dynamic Programming
//             to find minimum number of scalar multiplications.

#include <iostream>
#include <climits>
using namespace std;

// Function to find minimum multiplication cost
void matrixChainMultiplication(int p[], int n)
{
    int m[n][n];

    // Cost is 0 when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // length is the chain length
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] +
                           m[k + 1][j] +
                           p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    cout << "Minimum number of scalar multiplications: "
         << m[1][n - 1] << endl;
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions of matrices:\n";
    cout << "For matrices A1, A2, ..., An, enter "
         << n + 1 << " dimensions:\n";

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainMultiplication(p, n + 1);

    return 0;
}
