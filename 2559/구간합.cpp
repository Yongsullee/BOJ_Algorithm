#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// 0 번째 Index에 0을 넣어 vector를 초기화합니다.
vector<ll> preSum(1, 0);
int N, K;

ll MaxSum(int interval)
{
    ll tmpSum = -9999;
    for (int i = 1; i <= N - interval + 1; ++i)
    {
        if (tmpSum > preSum[i + interval - 1] - preSum[i - 1])
            continue;
        else
            tmpSum = preSum[i + interval - 1] - preSum[i - 1];
    }
    return tmpSum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> N >> K;

    int tmp;
    for (int i = 1; i <= N; ++i)
    {
        cin >> tmp;

        preSum.push_back(preSum[i - 1] + tmp);
    }

    ll result;
    result = MaxSum(K);

    cout << result << endl;
}