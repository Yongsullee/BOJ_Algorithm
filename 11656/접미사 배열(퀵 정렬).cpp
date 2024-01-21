#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S;

int MedianOfThree(vector<string> &arr, int l, int r)
{
    int m = l + (r - l) / 2;

    if (arr[l] > arr[m])
    {
        swap(arr[l], arr[m]);
    }
    if (arr[l] > arr[r])
    {
        swap(arr[l], arr[r]);
    }
    if (arr[m] > arr[r])
    {
        swap(arr[m], arr[r]);
    }

    return m;
}

int Partition(vector<string> &arr, int l, int r)
{
    int pivIdx = MedianOfThree(arr, l, r);
    swap(arr[pivIdx], arr[r]);

    string piv = arr[r];
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

void QuickSort(vector<string> &arr, int l, int r)
{
    if (l < r)
    {
        int piv = Partition(arr, l, r);

        QuickSort(arr, l, piv - 1);
        QuickSort(arr, piv + 1, r);
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

    QuickSort(arr, 0, S.length() - 1);

    for (int i = 0; i < S.length(); ++i)
        cout << arr[i] << '\n';

    return 0;
}