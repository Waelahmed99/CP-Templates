#include <bits/stdc++.h>

using namespace std;

unsigned long long nCr(unsigned int n, unsigned int k)
{
    unsigned long long C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (unsigned int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

long long factorial(unsigned int n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

long long nPr(unsigned int n, unsigned int r)
{
    return factorial(n) / factorial(n - r);
}

unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = nCr(2 * n, n);

    // return 2nCn/(n+1)
    return c / (n + 1);
}