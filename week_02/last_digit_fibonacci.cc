#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i < n; ++i)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    

    std::cout << arr[n - 1];
}
