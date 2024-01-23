#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

int N;
vector<ll> arr;

int MedianOfThree(vector<ll> &arr, int l, int r)
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

int Partition(vector<ll> &arr, int l, int r)
{
    int pivIdx = MedianOfThree(arr, l, r);
    swap(arr[pivIdx], arr[r]);

    ll piv = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j)
    {
        if (arr[j] <= piv)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

void QuickSort(vector<ll> &arr, int l, int r)
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

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    // 퀵 정렬
    QuickSort(arr, 0, N - 1);

    // 투 포인터, 절대값이 가장 작은 수 찾기
    int left = 0;
    int right = N - 1;
    ll closeToZero = LLONG_MAX;

    pair<ll, ll> ans;

    while (left < right)
    {
        ll sum = arr[left] + arr[right];
        if (abs(sum) < abs(closeToZero))
        {
            closeToZero = sum;
            ans = make_pair(arr[left], arr[right]);
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum > 0)
        {
            right--;
        }
        else if (sum < 0)
        {
            left++;
        }
    }

    cout << ans.first << ' ' << ans.second;

    return 0;
}