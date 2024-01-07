#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>
using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
set<int> s;
vector<int> dist;

void bfs()
{
    vector<bool> visited(N + 1, false);
    queue<int> q;

    dist[X] = 0;
    q.push(X);
    visited[X] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto &neighbor : graph[cur])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
                dist[neighbor] = dist[cur] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K >> X;

    graph.resize(N + 1);
    dist.resize(N + 1, 0);

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }

    // BFS 수행
    bfs();

    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] == K)
            s.insert(i);
    }

    // 결과 출력
    if (s.empty())
    {
        cout << -1;
    }
    else
    {
        for (auto it = begin(s); it != end(s); ++it)
            cout << *it << '\n';
    }

    return 0;
}