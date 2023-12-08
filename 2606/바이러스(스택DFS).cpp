#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int N, M;
int res;

void DFS(int start, unordered_map<int,vector<int>>& graph)
{
    // 방문 여부
    vector<bool> visited(graph.size()+1, false);
    // 스택
    stack<int> s;
    
    s.push(start);
    visited[start] = true;
    // 스택 순회
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        
        for(int i=0; i<(int)graph[cur].size(); ++i)
        {
            int next = graph[cur][i];
            if(!visited[next])
            {
                visited[next] = true;
                s.push(next);
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
    
    // #1. um 컨테이너 형식의 그래프
    unordered_map<int, vector<int>> graph;
    
    // #2. 그래프 구성
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    // #3. DFS 호출
    DFS(1, graph);
    
    cout << res;
    
    return 0;
}