#include <iostream>
#include <climits>
using namespace std;

// Function to calculate minimum number of scalar multiplications
int matrixChainOrder(int p[], int n)
{
    int m[n][n];

    // Cost is 0 when multiplying one matrix.
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications is " << matrixChainOrder(arr, n) << endl;
    return 0;
}
