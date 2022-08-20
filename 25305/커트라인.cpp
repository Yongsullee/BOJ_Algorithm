#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    vector<int> v;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    // 비교 함수 객체 사용, greater<>()
    sort(begin(v), end(v), greater<>());

    cout << v[K - 1] << endl;
}