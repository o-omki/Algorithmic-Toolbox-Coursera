#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    long long arr[n];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < n; ++i)
        arr[i] = arr[i - 1] + arr[i - 2];
    

    std::cout << arr[n - 1];
}
