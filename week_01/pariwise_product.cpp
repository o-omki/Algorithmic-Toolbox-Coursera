#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);

    for (auto i = 0; i < n; ++i)
        std::cin >> arr[i];
    
    std::sort(arr.begin(), arr.end(), std::greater<long long>());

    std::cout << (long long)(arr[0] * arr[1]);

} 