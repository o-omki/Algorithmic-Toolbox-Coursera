#include <iostream>

long long pisano_num(long long m)
{
    int a = 0, b = 1, c;
    for (long long i = 1; i < m * m; ++i)
    {
        c = (a + b) % m;
        a = b;
        b = c;

        if (a == 0 && b == 1)
            return i;
            
    }
    return 9999;
}

long long fib(long long n, long long m)
{
    n = n % pisano_num(m);
    if (n == 0 || n == 1)
        return 1;

    long a = 1, b = 1, c;
    long long x = n;
    for (auto i = 2; i < n; ++i)
    {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return c % m;
}

int main()
{
    long long n;
    long long m;
    std::cin >> n >> m;
    std::cout << (long long)fib(n, m);
}