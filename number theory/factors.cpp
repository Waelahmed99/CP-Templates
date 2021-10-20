#include <bits/stdc++.h>

using namespace std;

vector<int> factorsOf(int n)
{
    vector<int> factors;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (n / i != i)
                factors.push_back(n / i);
        }
    }
}

vector<int> primeFactors(int n)
{
    vector<int> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

vector<int> factors;
vector<int> prime_factors;

// Number of factors.
void factorization(int n)
{
    factors.assign(n + 5, 2);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i * 2; j <= n; j += i)
            factors[j]++;
    }
}

void prime_factorization(int n)
{
    prime_factors.resize(n + 5, 0);
    for (int i = 2; i <= n + 1; i++)
    {
        if (!prime_factors[i])
        {
            for (int j = i; j <= n + 1; j += i)
                prime_factors[j]++;
        }
    }
}
