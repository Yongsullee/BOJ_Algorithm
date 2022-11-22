/*
    문제:
        C(N,K) % 10007 결과 출력
    설명:
        1. N! / K!(N-K)!
        2. 파스칼의 삼각형 or 파스칼 공식 이용
        3. C(N-1, K-1) = C(N-1, K)
        4. 추가적으로, if N=0, C(N,K) = 0 이며, if K=0, C(N,K) = 1
        5. 동적 계획법을 통해 DP[N][K] 의 값을 구합니다.
*/

#include <iostream>
typedef long long ll;
using namespace std;

int N, K;
ll DP[1001][1001] = {0,};

int main()
{
    cin >> N >> K;
    
    if(N == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<=K; j++)
        {
            if(j == 0) DP[i][j] = 1;
            else if(i == j) DP[i][j] = 1;
            else DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
            
            DP[i][j] %= 10007;
        }
    }
    
    cout << DP[N][K] % 10007 << endl;
}

