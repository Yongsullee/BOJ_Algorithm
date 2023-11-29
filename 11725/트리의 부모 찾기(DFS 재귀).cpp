#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int N;

void DFS(int cur, unordered_map<int, vector<int>>& tree, vector<bool>& visited, vector<int>& parent)
{
    visited[cur] = true;
    for(const auto& next : tree[cur])
    {
        if(!visited[next] && parent[next] == INT_MAX)
        {
            parent[next] = cur;
            DFS(next, tree, visited, parent);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    // unordered_map 형식의 트리
    unordered_map<int, vector<int>> tree;
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 부모 노드 목록
    vector<int> parent(N+1, INT_MAX);
    
    for(int i=0; i<N-1; i++)
    {
        int parent, child;
        
        cin >> parent >> child;
        // 트리 구성
        tree[parent].push_back(child);
        tree[child].push_back(parent);
    }
    
    DFS(1, tree, visited, parent);
    
    for(int i=2; i<=N; i++)
        cout << parent[i] << '\n';
    
    return 0;
}