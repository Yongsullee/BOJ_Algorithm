#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M;

void Prim(unordered_map<int, vector<pair<int,int>>>& graph)
{
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 우선 순위 큐, 가중치 기준 최소 힙
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int MSTWeight = 0;
    
    // 1을 시작 노드로, 우선순위 큐에 삽입
    pq.push({0, 1});
    
    while(!pq.empty())
    {
        int weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
     
        if(visited[cur])
            continue;
        
        visited[cur] = true;
        MSTWeight += weight;
        
        // pair<int, int> : 가중치 + 인접 정점
        for(const auto& pair : graph[cur])
        {
            pq.push(pair);
        }
    }
    
    cout << MSTWeight;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    // a 정점에 대해서 pair.first = 인접 정점, pair.second = 가중치
    unordered_map<int, vector<pair<int,int>>> graph;
    
    while(M--)
    {
        int a, b, c;
        
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    
    Prim(graph); 
    
    return 0;
}