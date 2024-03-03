#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N;
vector<vector<int>> graph;
vector<int> scores;
vector<bool> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    graph.resize(N + 1);
    scores.resize(N + 1, 0);
    visited.resize(N + 1, false);

    while (true)
    {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1)
            break;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        queue<pair<int, int>> q;
        q.push({i, 0});
        visited.assign(N + 1, false);

        while (!q.empty())
        {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (visited[cur])
                continue;
            visited[cur] = true;

            scores[i] = max(scores[i], dist);

            for (int next : graph[cur])
            {
                if (!visited[next])
                {
                    q.push({next, dist + 1});
                }
            }
        }
    }

    int minMaxScore = INF;
    for (int i = 1; i <= N; ++i)
    {
        minMaxScore = min(minMaxScore, scores[i]);
    }

    vector<int> candidates;
    for (int i = 1; i <= N; ++i)
    {
        if (scores[i] == minMaxScore)
        {
            candidates.push_back(i);
        }
    }

    cout << minMaxScore << ' ' << candidates.size() << '\n';
    for (int candidate : candidates)
    {
        cout << candidate << ' ';
    }
    cout << '\n';

    return 0;
}
