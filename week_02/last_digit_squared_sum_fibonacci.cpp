#include <iostream>
#include <math.h>

long long fibo(long n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (round(pow(phi, n) / sqrt(5)));
}

int main()
{
    long n;
    std::cin >> n; 
    n %= 60;

    std::cout << (fibo(n) * (fibo(n + 1))) % 10;
}