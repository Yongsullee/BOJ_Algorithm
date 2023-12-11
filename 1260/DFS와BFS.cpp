#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V; 

void DFS(int start, unordered_map<int, vector<int>>& graph)
{
    vector<bool> visited(N+1, false);
    stack<int> s;
    
    s.push(start);
    
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        
        if(!visited[cur])
        {
            visited[cur] = true;
            cout << cur << ' ';
        }
        
        for(int i=(int)graph[cur].size()-1; i>= 0; --i)
        {
            if(!visited[graph[cur][i]])
            {
                s.push(graph[cur][i]);
            }
        }
    }
}

void BFS(int start, unordered_map<int, vector<int>>& graph)
{
    vector<bool> visited(N+1, false);
    queue<int> q;
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        cout << cur << ' ';
        
        for(int i=0; i<(int)graph[cur].size(); ++i)
        {
            if(!visited[graph[cur][i]])
            {
                visited[graph[cur][i]] = true;
                q.push(graph[cur][i]);
            }
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;
    
    unordered_map<int, vector<int>> graph;
    
    while(M--)
    {
        int a, b;
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // 인접 정점 목록을 오름차순 정렬
    for(auto& pair : graph)
    {
        sort(begin(pair.second), end(pair.second));    
    }
    
    // #1. DFS
    DFS(V, graph);
    
    cout << '\n';
    
    // #2. BFS
    BFS(V, graph);
    
    return 0;
}