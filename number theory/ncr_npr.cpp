#include <bits/stdc++.h>

using namespace std;

long long nCr(int n, int k)
{
    long long C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

long long factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

long long nPr(int n, int r)
{
    return factorial(n) / factorial(n - r);
}