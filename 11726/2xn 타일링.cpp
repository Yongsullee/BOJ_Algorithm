/*
    @문제 : 2X1 타일, 1X2 타일, 이 두가지 타일 종류를 통해 2Xn 직사각형을 채울 수 있는 모든 경우의 수
    @설명
        1. 2x2 직사각형 : 2x1 타일 2개 -> 1가지 + 1x2 타일 -> 1개(x2) -> 1가지 = 총 2개 경우
        2. 2X3 직사각형 : 2X1 타일 3개 -> 1 가지 + 1X2 타일 -> 1개(X2) -> 2가지 = 총 3개 경우
        3. 2X4 직사각형 : 2X1 타일 4개 -> 1 가지 + 1X2 타일 -> 2개(x2) -> 4가지 = 총 5개 경우
        .
        .
        .
        5. 결과적으로, dp[i] = (dp[i-1] + dp[i-1]) % MOD 해줍니다. 숫자가 커질 경우를 대비해 MOD 연산을 미리 수행해줍니다.
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1001] = {
    0,
    1,
    2,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n];

    return 0;
}