#include <iostream>
using namespace std;
typedef long long ll;

long long preSum[100001] = {0,};

int main()
{
    // 수행 시간 감소를 위한 라인
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    int tmp;
    for(int i=1; i<=N; i++)
    {
        cin >> tmp;
        preSum[i] = preSum[i-1] + tmp;
    }
    
    for(int i=0; i<M; i++)
    {
        // 구간의 첫 번째, l(left) + 구간의 마지막, r(right)
        int l, r;
        cin >> l >> r;
        cout << preSum[r] - preSum[l-1] << "\n";
    }
}