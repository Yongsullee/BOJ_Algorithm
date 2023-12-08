#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int V, E, answer;

// #1. Prim 알고리즘
void Prim(int start, vector<vector<pair<int,int>>>& graph)
{
    // #방문 여부
    vector<bool> visited(V+1, false);
    // 우선 순위 큐 : pair<int, int> 의 first 기준 최소힙
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, start});
    // 우선순위 큐 순회
    while(!pq.empty())
    {
        int weight = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(!visited[cur])
        {
            visited[cur] = true;
            answer += weight;
            
            for(const auto& edge : graph[cur])
            {
                if(!visited[edge.second])
                {
                    pq.push(edge);
                }
            }
        }
    }
    
    cout << answer;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> V >> E;
    
    // 2차원 vector 형식의 graph 선언
    vector<vector<pair<int,int>>> graph(V+1);
    // 그래프 구성
    for(int i=0; i<E; ++i)
    {
        int from, to, weight;
        
        cin >> from >> to >> weight;
        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }
    // Prim 알고리즘 호출
    Prim(1, graph);
    
    return 0;
}
