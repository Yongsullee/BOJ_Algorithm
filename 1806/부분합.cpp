/*
    @문제 : 부분 합이 S가 되는 최소 길이
    @설명
        1. Prefix Sum + 투 포인터 활용
        2. left와 right를 같은 위치에서 출발 시킨다.
        3. 만약, left == right 일때, Sum이 S와 크거나 같을 경우, left를 증가시킵니다.
        4. 만약,
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef long long ll;

int N;
ll S;
vector<ll> prefixSum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;

    prefixSum.resize(N, 0);

    for (int i = 1; i <= N; ++i)
    {
        int tmp;
        cin >> tmp;

        prefixSum[i] = prefixSum[i - 1] + tmp;
    }

    int left = 1;
    int right = 1;
    int minDist = INT_MAX;
    while (left <= right && right <= N && left <= N)
    {
        ll sum = prefixSum[right] - prefixSum[left - 1];
        if (sum >= S)
        {
            minDist = min(minDist, right - left + 1);
            left++;
        }
        else
        {
            right++;
        }
    }

    if (minDist != INT_MAX)
        cout << minDist;
    else
        cout << 0;

    return 0;
}