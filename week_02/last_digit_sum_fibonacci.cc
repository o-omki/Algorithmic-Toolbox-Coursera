#include <iostream>
#include <cmath>


long long fibo(long long n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (round(pow(phi, n) / sqrt(5)));
}

int main()
{
    long long n;
    std::cin >> n;
    // if (n == 0)
    //     std::cout << 0;
    
    // else if (n == 1)
    //     std::cout << 1;
    
    // else
    // {

    //     long long a = 1, b = 1, c, sum = 2;

    //     for (auto i = 2; i < n; ++i)
    //     {
    //         c = (a + b) % 10;
    //         sum += c;
    //         a = b; 
    //         b = c;

    //     }
    //     std::cout <<  sum % 10;
    // }
    n %= 60; // Pisano period of 10 is 60
    std::cout << fibo(n + 2)%10 - 1;
}