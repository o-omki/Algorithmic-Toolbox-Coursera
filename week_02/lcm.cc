#include <iostream>

long long gcd(long a, long  b)
{
    if (b == 0)
        return a;
    
    return gcd(b, a % b);
}
int main()
{
    long a, b;
    std::cin >> a >> b;

    std::cout << (long long)(a / gcd(a, b) * b);

}