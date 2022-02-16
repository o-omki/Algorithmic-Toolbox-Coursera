#include <iostream>
#include <limits>

const int GenerateChange(const int m)
{
    const int denom[] = {1, 3, 4};
    int num_coins[m + 1];
    num_coins[0] = 0;

    for (auto i = 1; i <= m; ++i)
    {
        num_coins[i] = std::numeric_limits<int>::max();

        for (auto &j: denom)
            if (i >= j)
            {
                int coins = num_coins[i - j] + 1;

                if (coins < num_coins[i])
                    num_coins[i] = coins;         
            }
    }

    return num_coins[m];    
}

int main()
{

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int m;
    std::cin >> m;
    std::cout << GenerateChange(m);
}