#include <iostream>
#include <algorithm>
using namespace std;

int N[100000];
int dp[100000];

/*
    설명:
        복잡하게 생각하지 않고, 이전의 합들과 현재 항목을 비교합니다.
        result = dp[i-1] + N[i] vs N[i]
*/

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> N[i];
    }

    dp[0] = N[0];
    int result = dp[0];

    for (int i = 1; i < T; i++)
    {
        dp[i] = max(dp[i - 1] + N[i], N[i]);
        result = max(result, dp[i]);
    }
    cout << result << endl;
}