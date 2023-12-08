#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M, R;

<<<<<<< HEAD
void DFS(int cur, int &curSeq, vector<int> &seq, vector<vector<int>> &graph, vector<bool> &visited)
{
    // #1. 방문여부 체크
    visited[cur] = true;
    // #2. 현재 자신의 방문 순서 갱신
    seq[cur] = curSeq++;

    // #3. 재귀 수행
    for (int next = 0; next < (int)graph[cur].size(); ++next)
    {
        int nextNode = graph[cur][next];
        if (!visited[nextNode])
        {
            DFS(nextNode, curSeq, seq, graph, visited);
=======
// 재귀를 활용한 DFS 구현
void DFS(int cur, int& curSeq, vector<int>& seq, vector<vector<int>>& graph, vector<bool>& visited)
{
    // 방문 여부 체크
    visited[cur] = true;
    // 현재 정점의 방문 순서 업데이트
    seq[cur] = curSeq++;
    
    for(int next=0; next<(int)graph[cur].size(); ++next)
    {
        int nextNode = graph[cur][next];
        if(!visited[nextNode])
        {
            // DFS 재귀 호출
           DFS(nextNode, curSeq, seq, graph, visited);
>>>>>>> b6263401cbacc21434fb45e9af91a51432990f2c
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
<<<<<<< HEAD

    cin >> N >> M >> R;

    // 2차원 벡터 형식의 그래프
    vector<vector<int>> graph(N + 1);
    // 방문 순서, 0으로 초기화, 방문하지 않았을 경우 갱신이 되지 않은 정점은 순서가 0으로 출력되도록
    vector<int> seq(N + 1, 0);
    // 방문 여부
    vector<bool> visited(N + 1, false);
    // 현재 순서
    int curSeq = 1;

    // #2. 그래프 구성
    for (int i = 0; i < M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;

        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    // #4. 각 노드 별 인접 정점을 오름차순 정렬
    for (auto &next : graph)
    {
        sort(begin(next), end(next));
    }

    // #5. DFS 수행
    DFS(R, curSeq, seq, graph, visited);

    for (int i = 1; i <= N; ++i)
    {
        cout << seq[i] << '\n';
    }

=======
    
    cin >> N >> M >> R;
    
    // 2차원 벡터 형식의 그래프
    vector<vector<int>> graph(N+1);
    // 방문 순서, 0으로 초기화
    vector<int> seq(N+1, 0);
    // 방문 여부
    vector<bool> visited(N+1, false);
    // 현재 순서
    int curSeq = 1;
    
    // #2. 그래프 구성
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        cin >> node1 >> node2;
        
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    
    // #4. 각 노드 별 인접 정점을 오름차순 정렬
    for(auto& next : graph)
    {
        sort(begin(next), end(next));
    }
    
    // #5. DFS 수행
    DFS(R, curSeq, seq, graph, visited);
    
    for(int i=1; i<= N; ++i)
    {
        cout << seq[i] << '\n';
    }
    
>>>>>>> b6263401cbacc21434fb45e9af91a51432990f2c
    return 0;
}