#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> time;
vector<vector<int>> graph;
vector<int> dp;
vector<bool> visited;

// 위상 정렬을 수행하는 재귀 DFS
void DFS(int node)
{
    // #1. 방문 여부 체크
    visited[node] = true;
    // #2. 다음 레벨 정점들 수회
    for (auto next : graph[node])
    {
        // 재귀 DFS
        if (!visited[next])
            DFS(next);
        // 현재 방문한 건물의 최종 시간 비용을 max(현재 건물의 시간 비용, 선행 건물의 시간 비용)로 갱신합니다.
        dp[node] = max(dp[node], dp[next]);
    }
    // #3. 모든 작업을 마치고, 현재 건물을 짓는데 걸리는 시간 비용을 최종 시간 비용에 더해줍니다.
    dp[node] += time[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 건물 별 건설 시간
    time.resize(N + 1);
    // #2. 2차원 vector 형식의 그래프
    graph.resize(N + 1);
    // #3. 각 정점의 최종 건설 시간 DP
    dp.resize(N + 1, 0);
    // #4. 방문 여부
    visited.resize(N + 1, false);

    // #5. 그래프 구성 후행 빌딩(높은 레벨) -> 선행 빌딩(낮은 레벨)
    for (int i = 1; i <= N; ++i)
    {
        cin >> time[i];
        while (true)
        {
            int building;
            cin >> building;
            if (building == -1)
                break;
            // *** 후행 빌딩의 인접 정점으로 선행 빌딩으로 구성
            // *** DFS의 특성상 '재귀'를 활용해 낮은 레벨의 작업을 먼저 처리하고
            // *** 재귀적으로 올라오며 높은 레벨의 작엄들을 처리합니다.
            // *** 따라서, 후행 빌딩은 선행 빌딩들의 시간 비용들을 합산하며 올라오며
            // *** DP에 저장된 선행 빌딩들듸 시간 비용을 통해 본인의 최대 시간 비용을 계산해줍니다!
            graph[i].push_back(building);
        }
    }

    // #6. 재귀 DFS 활용 위상 정렬 수행
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
            DFS(i);
    }

    for (int i = 1; i <= N; ++i)
        cout << dp[i] << '\n';

    return 0;
}
