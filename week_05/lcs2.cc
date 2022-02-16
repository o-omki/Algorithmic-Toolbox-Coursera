#include <iostream>
#include <vector>
#include <algorithm>

int LCS(const std::vector<long> &s1, const std::vector<long> &s2)
{
  int n = s1.size();
  int m = s2.size();

  if (m == 0 || n == 0)
    return 0;

  std::vector<std::vector<long>> memo(n + 1, std::vector<long>(m + 1));

  for (auto i = 1; i <= n; ++i)
  {
    for (auto j = 1; j <= m; ++j)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        memo[i][j] = memo[i - 1][j - 1] + 1;
      }
      else
      {
        memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
      }
    }
  }

  // for (auto x : memo)
  // {
  //   for (auto y: x)
  //     std::cout << y << " ";
    
  //   std::cout << "\n";
  // }

  return memo[n][m];
}

int main()
{
#ifdef LOCAL
  freopen("./input.txt", "r", stdin);
  freopen("./output.txt", "w", stdout);
#endif

  std::size_t n, m;
  std::vector<long> s1;
  std::vector<long> s2;

  std::cin >> n;
  for (auto i = 0; i < n; ++i)
  {
    long value;
    std::cin >> value;
    s1.push_back(value);
  }

  std::cin >> m;
  for (auto i = 0; i < m; ++i)
  {
    long value;
    std::cin >> value;
    s2.push_back(value);
  }

  std::cout << LCS(s1, s2);
}