#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    std::vector<long long > b(n);
    long long answer = 0;
    for (int i = 0; i < n; ++i)
    {
        long long value;                
        std::cin >> value;
        a[i] = value; 
    }

    for (int i = 0; i < n; ++i)
    {
        long long value; 
        std::cin >> value;
        b[i] = value; 
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (auto i = 0; i < n; ++i)
        answer += a[i] * b[i];
    
    std::cout << answer;

}