/*  *************************************************************************************************************************************

    목적:
        소인순해의 성질을 이용해 1 ~ N까지의 숫자 중 소인수로 2 혹은 5가 나오는 횟수 카운트합니다.
    설명:
        1.  소인수 분해의 성질에 따르면, 뒷 자리에 0을 만들기 위해선 10을 소인수 분해하면 나오는 2와 5가 필요합니다.
        2.  1 ~ N 범위의 숫자들을 소인수분해 했을 때 비교적 2보다 5가 나오는 횟수가 적겠죠? 그래서 소인수분해로 5가 나오는 횟수를 세는겁니다.
        3.  세는 방법은 N/5^1 + N/5^2 + ... N/5^N

*   ************************************************************************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    
    int ans = 0;
    for(int i=5; i<= N; i*=5)
    {
        ans += N/i;
    }
    cout << ans << endl;
}