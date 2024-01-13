// 문제 : 다익스트라 활용? 가장 짧은 싸이클을 찾는데 적절치 않다.
// 해결 : 플로이드-워셜 활용, dist[1][1]는 일반적으로 0이지만, '사이클'이 존재할 경우 dist[i][i]값이 갱신된다.

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int V, E;
vector<vector<int>> graph, dist;

void Floyd()
{
    for(int k=1; k <= V; ++k)
    {
        for(int u=1; u<=V; ++u)
        {
            for(int v=1; v<=V; ++v)
            {
                if(dist[u][k] != INT_MAX
                  && dist[k][v] != INT_MAX
                  && (dist[u][v] == INT_MAX || dist[u][v] > dist[u][k] + dist[k][v]))
                {
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
    
    int res = INT_MAX;
    for(int i=1; i<=V; ++i)
        res = min(res, dist[i][i]);
    
    if(res == INT_MAX) cout << -1;
    else cout << res;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    
    dist.resize(V+1, vector<int>(V+1, INT_MAX));
    
    while(E--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        dist[u][v] = w;
    }
    
    Floyd();
    
    return 0;
}