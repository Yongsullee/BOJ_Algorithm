#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

int N, M, X, res;
// #1. 그래프 선언, 2차원 벡터와 pair< 가중치, 도착 정점 > 형식
vector<vector<pair<int,int>>> graph;
// #2. 최단 경로 비용 목록
vector<int> dist, finDist;

void dijkstra(int start)
{
    dist.clear();
    dist.resize(N+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int weight = pq.top().first;
        
        pq.pop();
        
        if(weight > dist[cur])
            continue;
        
        for(const auto& edge : graph[cur])
        {
            int neighbor = edge.second;
            int new_dist = weight + edge.first;
            
            if(new_dist < dist[neighbor])
            {
                pq.push({new_dist, neighbor});
                dist[neighbor] = new_dist;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    
    graph.resize(N+1);
    dist.resize(N+1, INT_MAX);
    finDist.resize(N+1, 0);
    
    while(M--)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        
        graph[start].push_back({weight, end});
    }
    
    // #2-1. 다익스트라 : 각 정점으로 부터 X까지 걸리는 최단 경로 비용
    for(int i=1; i<=N; ++i)
    {
        dijkstra(i);
        finDist[i] = dist[X];
    }
    dijkstra(X);
    for(int i=1; i<=N; ++i)
    {
        finDist[i] += dist[i];
        res = max(res, finDist[i]);    
    }
    
    cout << res;
    
    return 0;
}