/*
 *   @문제 : 숫자 N을 /3, /2, -1 연산을 통해 1을 만들 수 있는 최소 연산 횟수 구하기
 *   @설명
 *           1. 먼저, dp[1] = 0번입니다.
 *           2. dp[i] 는 dp[i-1]+1번, dp[i/2]+1번, dp[i/3]+1번의 연산 횟수를 가집니다.
 *           3. 조건에 따라서, 위 세 가지 연산 중 어떠한 연산을 수행할지 결정하며 DP를 수행합니다.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    dp[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        // #1. -1 연산
        dp[i] = dp[i - 1] + 1;
        // #2. /2 연산
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[N];

    return 0;
}