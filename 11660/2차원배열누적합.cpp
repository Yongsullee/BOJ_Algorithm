#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int N, M;
int ans;

int main()
{
    // 수행 시간 감소를 위한 라인
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    
    for(int i=0; i<M; i++)
    {
        int firstX, firstY, secondX, secondY;
        cin >> firstX >> firstY >> secondX >> secondY;
        
        ans = dp[secondX][secondY] - dp[firstX-1][secondY] 
            - dp[secondX][firstY-1] + dp[firstX-1][firstY-1];
        
        cout << ans << '\n';
    }
}


// 참조 : https://donggoolosori.github.io/2020/10/13/boj-11660/ 

/************************** 시간 초과 실패 코드 **************************/

// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// typedef long long ll;

// int N, M;

// vector<ll> prefixSum(1,0);

// long long calcInterval(const int firstA, const int firstB, const int secondA, const int secondB)
// {
//     ll ans;
//     ll left =0, right =0; 
    
//     for(int i=0; i<=(secondA - firstA); i++)
//     {
//         left = (N*firstA) - (N-firstB) + (N*i);
//         right = (N*firstA) - (N-secondB) + (N*i);
        
//         ans += prefixSum[right] - prefixSum[left-1];
//     }
    
//     return ans;
// }

// int main()
// {
//     // 수행 시간 감소
//     ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
//     cin >> N >> M;
    
//     for(int i=1; i<=(N*N); i++)
//     {
//         ll tmp;
        
//         cin >> tmp;
//         prefixSum.push_back(prefixSum[i-1] + tmp);
//     }
    
//     for(int i=0; i<M; i++)
//     {
//         // [A1][B1], [A2][B2]
//         int a1, b1, a2, b2;
//         int ret;
        
//         cin >> a1 >> b1 >> a2 >> b2;
        
//         ret = calcInterval(a1, b1, a2, b2);
        
//         cout << ret << '\n';
//     }
// }