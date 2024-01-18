#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N = 9;
vector<int> heights;

int MedianOfThree(vector<int> &arr, int l, int r)
{
    int m = l + (r - l) / 2;
    if (arr[l] > arr[m])
        swap(arr[l], arr[m]);
    if (arr[l] > arr[r])
        swap(arr[l], arr[r]);
    if (arr[m] > arr[r])
        swap(arr[m], arr[r]);

    return m;
}

int Partition(vector<int> &arr, int l, int r)
{
    int pivIdx = MedianOfThree(arr, l, r);
    swap(arr[pivIdx], arr[r]);

    int piv = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        if (arr[j] <= piv)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

void QuickSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int piv = Partition(arr, l, r);

        QuickSort(arr, l, piv - 1);
        QuickSort(arr, piv + 1, r);
    }
}

void FindSeven(vector<int> &arr)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int sum = 0;
            for (int k = 0; k < N; ++k)
            {
                if (k == i || k == j)
                    continue;
                sum += arr[k];
            }
            if (sum == 100)
            {
                for (int k = 0; k < N; ++k)
                {
                    if (k == i || k == j)
                        continue;
                    cout << heights[k] << '\n';
                }
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    heights.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> heights[i];

    // #1. 퀵 정렬
    QuickSort(heights, 0, N - 1);

    // #2. 키의 총합이 100이 되는 7명 찾기
    FindSeven(heights);

    return 0;
}