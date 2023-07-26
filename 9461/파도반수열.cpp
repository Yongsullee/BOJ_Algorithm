/*
    문제 :
        동적 계획법을 활용해 파도반 수열을 구현합니다.
    설명 :
        1. 파도반 수열의 점화식
            P(n) = P(n-2) + P(n-3), n >= 4
            P(n) = 1, n = 1, 2, 3
        2. 자료형 주의, 피보나치 수열과 마찬가지로 수가 기하급수적으로 커집니다.
*/

#include <iostream>
#include <vector>
using namespace std;

long long dp[101] = {0, 1, 1, 1};

long long PadovanDP(int n)
{
    for(int i=4; i<= n; i++)
    {
        dp[i] = dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        cout << PadovanDP(N) << '\n';
    }
}