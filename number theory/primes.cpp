#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}