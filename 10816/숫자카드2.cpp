// 1. Map 컨테이너를 활용했지만, 2번 코드보다 소요 시간과 메모리 사용량이 비교적 훨씬 높음...

#include <iostream>
#include <map>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    // 숫자 + 개수
    map<ll, int> m;
    vector<ll> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;

        m[num]++;
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        ll num2;
        cin >> num2;

        v.push_back(m[num2]);
    }

    for (int val : v)
        cout << val << " ";
}

// 2. Sort 알고리즘과 lower_bound와 upper_bound 활용 코드, 시간 + 성능 모두 훨씬 뛰어남

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<ll> v;
    vector<int> v2;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        ll num;
        cin >> num;

        v.push_back(num);
    }

    sort(begin(v), end(v));

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        ll num2;
        cin >> num2;

        auto upper = upper_bound(begin(v), end(v), num2);
        auto lower = lower_bound(begin(v), end(v), num2);

        v2.push_back(upper - lower);
    }

    for (auto val : v2)
        cout << val << " ";
}