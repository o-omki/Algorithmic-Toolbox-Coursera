#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

bool compare(const long a, const long b)
{
    std::string s1 = std::to_string(a) + std::to_string(b);
    std::string s2 = std::to_string(b) + std::to_string(a);

    return s1 > s2;
}

int main()
{
    #ifdef LOCAL
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    int n;
    long value;
    std::vector<long> nums;
    
    std::cin >> n;

    for (auto i = 0; i < n; ++i)
    {
        std::cin >> value;
        nums.push_back(value);
    }

    std::sort(nums.begin(), nums.end(), compare);

    long long answer = 0;
    for (auto &i: nums)
        std::cout << i;
}