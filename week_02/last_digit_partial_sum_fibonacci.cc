#include <iostream>
#include <cmath>

long long fibo(long n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (round(pow(phi, n) / sqrt(5)));
}

int main()
{
    long long a = 1, b = 1, c, sum = 0;
    long long n, m, x = 0;
    std::cin >> m >> n;
    // if (n == 0)
    // {
    //     std::cout << 0;
    //     return 0;
    // }
    // if (m == 0)
    // {
    //     ++sum;
    //     ++x;

    // }
    
    // else if (m == 1)
    // {
    //     sum += 2;        
    //     x += 2;

    // }

    // for (auto i = 2; i < n; ++i)
    // {
    //     c = (a + b) % 10;
    //     a = b; 
    //     b = c;
    //     if (i >= m + x - 1 )
    //         sum = (sum + c) % 10;

    // }

    std::cout << (fibo(n + 2) - fibo(m + 1))%10;


}