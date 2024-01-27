#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<int> arr1(N);
    vector<int> arr2(M);

    for (int i = 0; i < N; ++i)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> arr2[i];
    }

    vector<int> res(N + M);

    int leftIdx = 0;
    int rightIdx = 0;
    int resIdx = 0;

    while (leftIdx < N && rightIdx < M)
    {
        if (arr1[leftIdx] < arr2[rightIdx])
        {
            res[resIdx++] = arr1[leftIdx++];
        }
        else
        {
            res[resIdx++] = arr2[rightIdx++];
        }
    }

    while (leftIdx < N)
    {
        res[resIdx++] = arr1[leftIdx++];
    }

    while (rightIdx < M)
    {
        res[resIdx++] = arr2[rightIdx++];
    }

    for (int i = 0; i < N + M; ++i)
        cout << res[i] << ' ';

    return 0;
}