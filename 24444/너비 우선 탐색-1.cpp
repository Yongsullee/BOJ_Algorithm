#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, R;

// BFS 구현, 큐 활용
void BFS(int start, unordered_map<int, vector<int>>& graph, vector<int>& seq)
{
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 큐
    queue<int> q;
    // 방문 순서
    int curSeq = 1;
    
    // 시작 노드
    visited[start] = true;
    q.push(start);
    
    while(!q.empty())
    {
        // 큐의 첫 번째 항목
        int cur = q.front();
        q.pop();
        
        // 방문 순서 업데이트
        seq[cur] = curSeq++;
        
        for(int i=0; i<(int)graph[cur].size(); i++)
        {
            // 인접 정점
            int neighbor = graph[cur][i];
            // 방문 여부 체크
            if(!visited[neighbor])
            {
                // 방문 순서 갱신
                visited[neighbor] = true;
                // 큐에 삽입
                q.push(neighbor);
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> R;
    
    // um 형식의 graph 선언
    unordered_map<int, vector<int>> graph;
    // 방문 순서
    vector<int> seq(N+1, 0);
    
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    // 오름차순 정렬
    for(auto& edge : graph)
    {
        sort(begin(edge.second), end(edge.second));
    }
    
    // BFS 호출
    BFS(R, graph, seq);
    
    // 정답 출력
    for(int i=1; i<(int)seq.size(); i++)
        cout << seq[i] << '\n';
     
    return 0;
}