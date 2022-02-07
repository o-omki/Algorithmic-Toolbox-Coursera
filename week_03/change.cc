#include <iostream>

int change(int m)
{
    int count = 0;
    int deno[] = {10, 5, 1};
    for (int i = 0; i < 3; ++i)
    {
        if (m == 0)
            return count;
        
        count = count + (m / deno[i]);
        m = m % deno[i];
    }
    return count;
}

int main()
{
    #ifdef LOCAL
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    int m; 
    std::cin >> m;
    std::cout << change(m);
}