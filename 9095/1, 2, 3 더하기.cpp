/*
    @문제 : 1, 2, 3의 합으로 숫자 n을 구할 수 있는 경우의 수
    @설명
            1. n에 대한 경우의 수는 dp[n-1] + dp[n-2] + dp[n-3] 과 같다
            2. 점화식, dp[n] = dp[n-1] + dp[n-2] + dp[n-2], when n > 3
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int T, n;
int dp[11] = {
    0,
    1,
    2,
    4,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n;

        if (n < 4)
        {
            cout << dp[n] << '\n';
            continue;
        }

        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n] << '\n';
    }

    return 0;
}