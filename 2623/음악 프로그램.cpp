#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int N, M; // N = 가수의 수, M = 보조PD의 수 

// DFS
void DFS(int node, vector<vector<int>>& graph,
         vector<bool>& visited, vector<bool>& recStack,
         stack<int>& s, bool& IsCyclic)
{
    // 방문 여부 체크
    visited[node] = true;
    // 재귀 스택에 추가
    recStack[node] = true;
    // 재귀 DFS 수행
    for(int next : graph[node])
    {
        // #1. 아직 방문하지 않았다면, DFS를 재귀적으로 정상적으로 수행
        if(!visited[next])
        {
            DFS(next, graph, visited, recStack, s, IsCyclic);
        }
        // #2. 방문한적이 있으며, 이미 재귀 스택에 들어있을 경우 순환 여부 존재
        else if(recStack[next])
        {
            IsCyclic = true;
            return;
        }
    }
    // 재귀 스택에서 해당 노드를 해제
    recStack[node] = false;
    // 스택에 현재 정점을 삽입
    s.push(node);
    
}

// 위상 정렬(Topological Sort)
void TopologicalSort(vector<vector<int>>& graph)
{
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 재귀 스택
    vector<bool> recStack(N+1, false);
    // 스택
    stack<int> s;
    // 순환 여부 체크
    bool IsCyclic = false;
    
    for(int i=1; i<=N; ++i)
    {
        // #1. DFS 수행
        if(!visited[i])
        {
            DFS(i, graph, visited, recStack, s, IsCyclic);
        }
        // #2. 순환 구조가 있다면, 0을 출력
        if(IsCyclic)
        {
            cout << 0;
            return;
        }
    }
    
    // 순환 구조가 없이, 정상적으로 위상 정렬을 모두 마쳣을 경우
    while(!s.empty())
    {
        cout << s.top() << '\n';
        s.pop();
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    // #1. 2차원 vector 형식의 그래프 구성
    vector<vector<int>> graph(N+1);
    
    // #2. 그래프 구성
    while(M--)
    {
        int num;
        cin >> num;
        
        int prevSinger = -1;
        for(int i=0; i<num; i++)
        {
            int singerNum;
            cin >> singerNum;
            
            if(prevSinger != -1)
                graph[prevSinger].push_back(singerNum);
            
            prevSinger = singerNum;
        }
    }
    
    // #3. 위상 정렬(TopologicalSort)
    TopologicalSort(graph);
    
    return 0;
}