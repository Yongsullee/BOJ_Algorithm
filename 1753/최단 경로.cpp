/*
    [문제] : 다익스트라 활용 그래프의 단일 출발 최단 경로 값
    
    [풀이] : 다익스트라 알고리즘
    
    1. 2차원 벡터를 통해 그래프 초기화, vector<vector<int>> 형식은 메모리 낭비가 크기 때문에, vector<vector<pair<int,int>>> 형식으로 그래프 선언
    2. 우선순위 큐 활용한 다익스트라 진행

*/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int V,E,K;

void Dijkstra(vector<vector<pair<int,int>>>& graph, int start)
{
    //방문 여부
    vector<bool> visited(V+1, false);
    //최단 경로
    vector<int> dist(V+1, INT_MAX);
    //우선 순위 큐 : pair< 최단 경로 값, 정점 >
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    //시작 정점 초기화
    dist[start] = 0;
    pq.push({0, start});
    
    //우선 순위 큐 순회
    while(!pq.empty())
    {
        // #1. 최단 경로 값이 가장 작은 정점 추출
        int cur_weight = pq.top().first;
        int cur_vertex = pq.top().second;
        
        pq.pop();
        
        if(visited[cur_vertex])
            continue;
        
        visited[cur_vertex] = true;
        
        // #2. 최소 최단 경로 값을 갖는 정점의 인접 노드들 방문
        for(auto next : graph[cur_vertex])
        {
            int next_vertex = next.first;
            int next_weight = next.second;
            
            // #3. 인접 노드들의 최단 경로 값 갱신 여부 확인
            int new_dist = dist[cur_vertex] + next_weight;
            if(new_dist < dist[next_vertex])
            {
                dist[next_vertex] = new_dist;
                pq.push({new_dist, next_vertex});
            }
        }
    }
    
    for(int i=1; i<=V; i++)
    {
        if(dist[i] == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // V = 정점의 개수, E = 간선의 개수, K = 시작 정점
    cin >> V >> E;
    cin >> K;
    // 그래프 초기화
    vector<vector<pair<int,int>>> graph(V+1);
    
    for(int i=0; i<E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v,w});
    }
    
    Dijkstra(graph, K);
    
    return 0;
}