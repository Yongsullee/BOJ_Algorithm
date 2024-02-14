#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, ans;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;

    for (const auto next : graph[node])
    {
        if (!visited[next])
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        // #1. 무방향 그래프, u 와 v 모두 시작 정점과 도착 정점이 될 수 있다.
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
            ans++;
        }
    }

    cout << ans;

    return 0;
}