#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>
#include <queue>
using namespace std;

int N;

// 큐를 활용하는 너비 우선 탐색 정의
void BFS(int start, unordered_map<int, vector<int>>& tree, vector<bool>& visited, vector<int>& parent)
{
    // 큐 선언
    queue<int> q;
    // 큐에 시작 노드 삽입
    q.push(start);
    // 시작 노드 방문 여부 체크
    visited[start] = true;
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(const auto& neighbor : tree[cur])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = cur;
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
    
    cin >> N;
    
    // unordered_map 형식의 트리 선언
    unordered_map<int, vector<int>> tree;
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 부모 노드 목록
    vector<int> parent(N+1, INT_MAX);
    
    for(int i=0; i<N-1; i++)
    {
        int parent, child;
        
        cin >> parent >> child;
        
        // 문제의 트리는 계층 구조가 분명하지 않아서, 무방향 간선으로 가정
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }
    
    BFS(1, tree, visited, parent);
    
    for(int i=2; i<=N; ++i)
        cout << parent[i] << '\n';
    
    return 0;
}