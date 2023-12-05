#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, M, R;

void DFS(int node, int& curSeq,
         unordered_map<int, vector<int>>& graph,
         vector<bool>& visited, vector<int>& seq)
{
    // 방문 여부 업데이트
    visited[node] = true;
    // 방문 순서 업데이트
    seq[node] = curSeq++;
    
    for(int i=0; i<(int)graph[node].size(); ++i)
    {
        int next = graph[node][i];
        if(!visited[next])
        {
            DFS(next, curSeq, graph, visited, seq);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> R;
    
    // um 형식의 그래프 선언
    unordered_map<int, vector<int>> graph;
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 방문 순서, 방문 하지 않을 경우 '0'을 출력하기 위해 모두 0으로 초기화한다.
    vector<int> seq(N+1, 0);
    // 현재 방문 순서
    int curSeq = 1;
    
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        // 무방향 간선 : 간선 하나에 대해서 두 정점이 모두 from과 to가 될 수 있도록 한다.
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    // 내림차순 정렬
    for(auto& edge : graph)
    {
        // pair<int, vector<int>> 형식의 second가 인접 정점 목록
        sort(begin(edge.second), end(edge.second), greater<int>());
    }
    
    // R 정점을 시작정점으로 DFS 호출
    DFS(R, curSeq, graph, visited, seq);
    
    // 결과 출력
    for(int i=1; i<(int)seq.size(); ++i)
        cout << seq[i] << '\n';
    
    return 0;
}