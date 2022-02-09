#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

double loot(int W, std::map<double, std::vector<int>, std::greater<double>> items)
{
    double value = 0.0;
    for (auto item = items.begin(); item != items.end(); ++item)
    {
        if (W == 0)
            return value;
        
        int weight = std::min(W, item->second[1]);
        value += (double)item->first * weight;
        W -= weight;      

    }
    return value;
}

int main()
{
    #ifdef LOCAL
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    std::map<double, std::vector<int>, std::greater<double>> items;
    int n, W, v, w;
    std::cin >> n >> W;
    for (auto i = 0; i < n; ++i)
    {
        std::cin >> v >> w;
        items.insert({(double)v / w, {v, w}});
    }

    double values = loot(W, items);

    std::cout << std::fixed << std::setprecision(4) << values;


}