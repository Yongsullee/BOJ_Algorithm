#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int N, M;

// #1. 재귀 DFS 함수
void DFS(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, stack<int>& s)
{
    // #1. 방문 여부 체크
    visited[node] = true;
    // #2. 다음 정점 순회
    for(auto& next : graph[node])
    {
        if(!visited[next])
        {
            DFS(next, graph, visited, s);
        }
    }
    // #3. 현재 항목을 스택에 삽입
    s.push(node);
}

// #2. 재귀 DFS를 활용하는 위상 정렬 함수
void TopologicalSort(unordered_map<int, vector<int>>& graph)
{
    // #1. 방문 여부
    vector<bool> visited(N+1, false);
    // #2. 순서를 담은 스택
    stack<int> s;
    // #2. 재귀 DFS 수행
    for(int i=1; i<=N; ++i)
    {
        if(!visited[i])
            DFS(i, graph, visited, s);
    }
    // #3. 스택에서 결과 값 출력
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
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
    }
    // #3. 위상정렬 호출
    TopologicalSort(graph);
    
    return 0;
}