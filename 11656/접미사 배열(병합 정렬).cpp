#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;

void Merge(vector<string> &str, int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;

    vector<string> left(leftSize);
    vector<string> right(rightSize);

    for (int i = 0; i < leftSize; ++i)
        left[i] = str[l + i];

    for (int i = 0; i < rightSize; ++i)
        right[i] = str[m + 1 + i];

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = l;

    while (leftIdx < leftSize && rightIdx < rightSize)
    {
        if (left[leftIdx] <= right[rightIdx])
        {
            str[resIdx++] = left[leftIdx++];
        }
        else
        {
            str[resIdx++] = right[rightIdx++];
        }
    }

    while (leftIdx < leftSize)
    {
        str[resIdx++] = left[leftIdx++];
    }

    while (rightIdx < rightSize)
    {
        str[resIdx++] = right[rightIdx++];
    }
}

void MergeSort(vector<string> &str, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(str, l, m);
        MergeSort(str, m + 1, r);

        Merge(str, l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;

    vector<string> arr;

    for (int i = 0; i < S.length(); ++i)
        arr.push_back(S.substr(i, S.length() - i));

    MergeSort(arr, 0, S.length() - 1);

    for (int i = 0; i < S.length(); ++i)
        cout << arr[i] << '\n';

    return 0;
}