#include <iostream>

using namespace std;

#define N 4
#define K 2

int C(int**, int, int);

int main()
{
    int** F = new int* [N + 1];
    for (int i = 0; i < N + 1; ++i)
    {
        F[i] = new int[K + 1];
        for (int j = 0; j < K + 1; ++j)
        {
            F[i][j] = 0;
        }
    }
    C(F, N, K);
    delete[] F;
    return EXIT_SUCCESS;
}

int C(int** F, int n, int k)
{
    if (F[n][k] > 0)
    {
        cout << "* C (" << n << ", " << k << ") = " << F[n][k] << endl;
        return F[n][k];
    }
    else
    {
        if (k == 0 || k == n)
        {
            F[n][k] = 1;
        }
        else if (0 < k && k < n)
        {
            F[n][k] = C(F, n - 1, k) + C(F, n - 1, k - 1);
        }
        else
        {
            F[n][k] = 0;
        }
        cout << "C (" << n << ", " << k << ") = " << F[n][k] << endl;
        return F[n][k];
    }
}