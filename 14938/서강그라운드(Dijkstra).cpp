#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> p;

int n, m, r, maxItems, res;
vector<int> t;
vector<vector<p>> graph;

// 다익스트라 정의
void dijkstra(int start)
{
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, INT_MAX);
    priority_queue<p, vector<p>, greater<p>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        int cur_vertex = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();
        
        if(visited[cur_vertex])
            continue;
        
        visited[cur_vertex] = true;
        
        for(const auto& edge : graph[cur_vertex])
        {
            int neighbor_vertex = edge.second;
            int neighbor_weight = edge.first;
            
            int new_dist = cur_weight + neighbor_weight;
            if(dist[neighbor_vertex] > new_dist)
            {
                dist[neighbor_vertex] = new_dist;
                pq.push({new_dist, neighbor_vertex});
            }
        }
    }
    // 각 정점들의 최단 거리 비용을 순회하며 수색 범위 내 존재하는 지역들의 아이템 개수의 총합을 구합니다.
    int tmp = 0;
    for(int i=1; i<=n; ++i)
    {
        if(dist[i] <= m)
        {
            tmp += t[i];
        }
    }
    // 구할 수 있는 아이템 최대 개수 갱신
    res = max(res, tmp);
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
       
    t.resize(n+1);
    graph.resize(n+1);
    
    for(int i=1; i<=n; ++i)
        cin >> t[i];
    
    while(r--)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    // 다익스트라 수행
    for(int i=1; i<=n; ++i)
        dijkstra(i);
    
    // 정답 출력
    cout << res;
    
    return 0;
}