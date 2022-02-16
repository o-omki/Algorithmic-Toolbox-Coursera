#include <iostream>
#include <string>
#include <algorithm>

int OptimalDistance(const std::string &source, const std::string &target)
{
    const int length_01 = source.length();
    const int length_02 = target.length();

    if (length_01 == 0)
        return length_02;
    
    if (length_02 == 0)
        return length_01;
    
    int memo[length_01 + 1][length_02 + 1];

    for (auto row = 0; row <= length_01; ++row)
        for (auto col = 0; col <= length_02; ++col)
        {
            if (row == 0)
            {
                memo[row ][col] = col;
            }            
            else if (col == 0)
            {
                memo[row ][col] = row;
            }
            else if (source[row - 1] == target[col - 1])
            {
                memo[row ][col] = memo[(row - 1) ][col - 1];
            }
            else
            {
                memo[row ][col] = 1 + std::min({
                    memo[(row - 1) ][col],
                    memo[row ][col - 1],
                    memo[(row - 1) ][col - 1]
                });
            }
        }
    
    return memo[length_01][length_02];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::string string_01, string_02;
    std::cin >> string_01 >> string_02;

    std::cout << OptimalDistance(string_01, string_02);
}