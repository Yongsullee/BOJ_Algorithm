#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, R;

// 재귀를 활용한 DFS 구현
void DFS(int start, vector<vector<int>>& graph)
{
    // 방문 순서, 0으로 초기화
    vector<int> seq(N+1, 0);
    // 방문 여부, false로 초기화
    vector<bool> visited(N+1, false);
    // 스택 선언
    stack<int> s;
    // 현재 정점의 순서
    int curSeq = 1;
    
    // 시작 노드 스택에 삽입
    s.push(start);
    
    // 스택 순회
    while(!s.empty())
    {
        int cur = s.top();
        s.pop();
        
        if(visited[cur])
            continue;
        
        visited[cur] = true;
        seq[cur] = curSeq++;
        // '오름차순' 정렬되어 있기 때문에, 역순으로 순회하며 stack에 삽입
        for(int i=graph[cur].size()-1; i>= 0; --i)
        {
            // 방문 여부 체크
            if(!visited[graph[cur][i]])
            {
                // 스택에 삽입
                s.push(graph[cur][i]);
            }
        }
    }
    // 정답 출력
    for(int i=1; i<=N; ++i)
        cout << seq[i] << '\n';
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> R;
    
    // #1. 2차원 벡터 형식의 그래프
    vector<vector<int>> graph(N+1);
    
    // #2. 그래프 구성
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    // #3. 각 노드 별 인접 정점을 오름차순 정렬
    for(auto& next : graph)
    {
        sort(begin(next), end(next));
    }
    
    // #4. DFS 수행
    DFS(R, graph);
    
    return 0;
}