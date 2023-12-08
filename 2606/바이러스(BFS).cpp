#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M, res;

void BFS(int start, unordered_map<int, vector<int>>& graph)
{
    // 방문 여부
    vector<bool> visited(graph.size()+1, false);
    // 큐
    queue<int> q;
    
    // 시작 노드 삽입
    visited[start] = true;
    q.push(start);
    
    // queue 순회
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(auto& neighbor : graph[cur])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
                res++;
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    // #1. um 형식의 그래프 선언
    unordered_map<int, vector<int>> graph;
    // #2. 그래프 구성
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    // BFS 호출
    BFS(1, graph);
    
    // 정답 출력
    cout << res;
    
    return 0;
}