#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

bool pair_sort(const std::pair<int, int> p1, const std::pair <int, int> p2)
{
    return p1.second < p2.second;
}

std::vector<int> min_points(std::pair<int, int> points[], int n)
{
    std::sort(points, points + n, pair_sort);
    int i = 0, count = 0;

    std::vector<int> pts;
    while (i < n)
    {
        int p = i + 1;
        int end = points[i].second;
        int start = points[p].first;
        
        pts.push_back(end);

        if (p >= n)
            break;
        
        while (end >= start)
        {
            ++p;

            if (p >= n)
                break;
            
            start = points[p].first;
        }

        i = p;
    }
    return pts;



}
int main()
{
    #ifndef LOCAL
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    int n, v1, v2;
    std::cin >> n;
    std::pair<int, int> points[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> v1 >> v2;
        points[i] = {v1, v2};
    }

    std::vector<int> pts = min_points(points, n);
    n = pts.size();
    std::cout << n << "\n";
    for (auto i : pts)
        std::cout << i << ' ';
    


}