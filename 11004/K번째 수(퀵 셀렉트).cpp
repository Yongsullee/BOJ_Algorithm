#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);

    for (int i = 0; i < N; ++i)
        cin >> v[i];

    nth_element(v.begin(), v.begin() + K - 1, v.end());

    cout << v[K - 1];

    return 0;
}
