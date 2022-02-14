#include <iostream>
#include <vector>

int binary_search(const std::vector<int> v, int start, int end, const int value)
{
    int mid;

    while (end - start > 1)
    {
        mid = start + (end - start) / 2;

        if (v[mid] <= value)
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }

    if (v[start] == value)
        return start;
    
    if (v[end] == value)
        return end;
    
    return -1;

}

int main()
{

#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif

    int n, k, value;
    std::vector<int> v1;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        v1.push_back(value);
    }

    std::cin >> k;
    for (int i = 0; i < k; ++i)
    {
        std::cin >> value;
        std::cout << binary_search(v1, 0, n - 1, value) << " ";
    }
}