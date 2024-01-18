#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N = 9;
vector<int> heights;

void Merge(vector<int> &arr, int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    vector<int> left(leftSize);
    vector<int> right(rightSize);

    // #1. 왼쪽 부분 배열과 오른쪽 부분 배열 나누기
    for (int i = 0; i < leftSize; ++i)
        left[i] = arr[l + i];

    for (int i = 0; i < rightSize; ++i)
        right[i] = arr[m + 1 + i];

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;

    // #2. 삽입 정렬
    while (leftIdx < leftSize && rightIdx < rightSize)
    {
        if (left[leftIdx] <= right[rightIdx])
        {
            arr[resIdx++] = left[leftIdx++];
        }
        else
        {
            arr[resIdx++] = right[rightIdx++];
        }
    }

    // #3 잔당 처리
    while (leftIdx < leftSize)
    {
        arr[resIdx++] = left[leftIdx++];
    }

    while (rightIdx < rightSize)
    {
        arr[resIdx++] = right[rightIdx++];
    }
}

void MergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
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

    // #1. 병합 정렬
    MergeSort(heights, 0, N - 1);

    // #2. 키의 총합이 100이 되는 7명 찾기
    FindSeven(heights);

    return 0;
}