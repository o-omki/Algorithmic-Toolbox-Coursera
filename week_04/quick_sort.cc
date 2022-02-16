#include <iostream>
#include <vector>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Partition(std::vector<int> &v, int left, int right, int &low, int &high)
{
    if (right - left < 2)
    {
        if (v[right] < v[left])
            Swap(&v[left], &v[right]);
        
        low = left;
        high = right;
        return;
    }

    int mid = left;
    int pivot = v[right];
    
    while (mid <= right)
    {
        if (v[mid] > pivot)
        {
            Swap(&v[mid], &v[right--]);
        }
        else if (v[mid] == pivot)
        {
            ++mid;
        }
        else
        {
            Swap(&v[left++], &v[mid++]);
        }
    }

    low = left - 1;
    high = right + 1;
}

void QuickSort(std::vector<int> &v, int left, int right)
{
    while (left < right)
    {
        int low, high;

        Partition(v, left, right, low, high);

        if (low - left < right - high)
        {
            QuickSort(v, left, low);
            left = high;
        }
        else
        {
            QuickSort(v, high, right);
            right = low;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    std::vector<int> v;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int value;
        std::cin >> value;
        v.push_back(value);
    }

    QuickSort(v, 0, v.size() - 1);
    for (auto x : v)
        std::cout << x << " ";
}