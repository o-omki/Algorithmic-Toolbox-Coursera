#include <iostream>
#include <vector>

int main()
{
    #ifdef LOCAL
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    long long n;
    std::cin >> n;

    std::vector<long long> values;
    int i = 1;
    while (n!=0)
    {
        if (n < 2 * i + 1)
        {
            values.push_back(n);
            break;
        }

        else
        {
            values.push_back(i);
            n -= i; 
        }
        ++i;

    }
    std::cout << values.size() << "\n";
    for (auto &i: values)
        std::cout << i << " ";

}