#include <iostream>
#include <vector>

int refills(std::vector<int> stops, int d, int m)
{
    int total_refills = 0, lrefill = 0, crefill = 0;
    const std::size_t n = stops.size();

    while (crefill < n - 1 )
    {
        lrefill = crefill;
        int dist = stops[crefill + 1] - stops[lrefill];
        while (crefill < n - 1 && ( (stops[crefill + 1] - stops[lrefill]) <= m))
            ++crefill;
        
        if (lrefill == crefill)
            return -1;
        
        if (crefill < n - 1)
            ++total_refills;
    }
    return total_refills;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int d, m, n;
    std::cin >> d >> m >> n;

    std::vector<int> stops(n + 2);

    for (auto i = 1; i <= n; ++i)
    {
        int value;
        std::cin >> value;
        stops[i] = value;
    }

    stops[n + 1] = d;
    std::cout << refills(stops, d, m);
}