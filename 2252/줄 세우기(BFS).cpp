#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    // #1. um 형식의 그래프
    unordered_map<int, vector<int>> graph;
    
    // #2. 진입 차수
    vector<int> InDegree(N+1);
    
    // #3. 그래프 구성
    for(int i=0; i<M; ++i)
    {
        int node1, node2;
        
        cin >> node1 >> node2; 
        // 그래프에 삽입
        graph[node1].push_back(node2);
        // 진입 차수 갱신
        InDegree[node2]++;
    }
    
    // #4. queue 선언
    queue<int> q;
    
    // #5. 진입 차수가 0인 정점 queue에 삽입
    for(int i=1; i<=N; ++i)
    {
        if(InDegree[i] == 0)
            q.push(i);
    }
    
    // #6. 큐 순회
    while(!q.empty())
    {
        // 큐의 첫 번째 항목 제거
        int cur = q.front();
        q.pop();
        // 결과 출력
        cout << cur << ' ';
        // 첫 번째 항목의 인접 정점들 순회
        for(auto& neighbor : graph[cur])
        {
            InDegree[neighbor]--;
            if(InDegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    return 0;
}