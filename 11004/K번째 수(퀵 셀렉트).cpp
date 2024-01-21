

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int N, K;

int Partition(vector<ll> &arr, int l, int r)
{
    ll piv = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        if (arr[j] <= piv)
        {
            ++i;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

int QuickSelect(vector<ll> &arr, int l, int r, int k)
{
    if (l == r)
        return arr[l];

    int pivotIndex = Partition(arr, l, r);

    if (k == pivotIndex)
        return arr[k];
    else if (k < pivotIndex)
        return QuickSelect(arr, l, pivotIndex - 1, k);
    else
        return QuickSelect(arr, pivotIndex + 1, r, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    vector<ll> v(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    // k번째 수 출력
    cout << QuickSelect(v, 0, N - 1, K - 1);

    return 0;
}
