#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, MST;
vector<pair<int, int>> graph[1001];

void Prim(int start)
{
    // #1. 가중치 기준 최소 힙을 구성하는 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(N + 1, false);

    pq.push({0, start});
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;

        visited[cur] = true;

        MST += cost;

        for (const auto &neighbor : graph[cur])
        {
            int nextCost = neighbor.first;
            int nextPos = neighbor.second;

            if (!visited[nextPos])
            {
                pq.push({nextCost, nextPos});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    while (K--)
    {
        int ynk;
        cin >> ynk;

        graph[0].push_back({0, ynk});
        graph[ynk].push_back({0, 0});
    }

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    Prim(0);

    cout << MST;

    return 0;
}