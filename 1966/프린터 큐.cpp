/*
    설명 : STL의 priority_queue 활용, 우선 순위 큐 자료구조
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int T, N, M, tmp;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    cin >> T;
    
    while(T--)
    {
        cin >> N >> M;
        for(int i=0; i<N; i++)
        {
            cin >> tmp;
            q.push({i, tmp});
            pq.push(tmp);
        }
        int ans = 0;
        while(!q.empty())
        {
            int Idx = q.front().first;
            int Imp = q.front().second;
            q.pop();
            if(Imp == pq.top())
            {
                pq.pop();
                ans++;
                if(Idx == M)
                {
                    cout << ans << '\n';
                }
            }
            else
            {
                q.push({Idx, Imp});
            }
        }
    }
    
}