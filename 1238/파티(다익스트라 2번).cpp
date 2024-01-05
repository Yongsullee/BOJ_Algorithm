#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M, X;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph)
{
    vector<int> distance(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_vertex = pq.top().second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > distance[cur_vertex])
            continue;

        for (const auto& edge : graph[cur_vertex])
        {
            int neighbor = edge.second;
            int new_dist = cur_weight + edge.first;

            if (new_dist < distance[neighbor])
            {
                distance[neighbor] = new_dist;
                pq.push({new_dist, neighbor});
            }
        }
    }
    return distance;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<vector<pair<int, int>>> reversed_graph(N + 1);

    while (M--)
    {
        int start, end, weight;
        cin >> start >> end >> weight;

        graph[start].push_back({weight, end});
        reversed_graph[end].push_back({weight, start});
    }

    vector<int> distance_from_X = dijkstra(X, graph);
    vector<int> distance_to_X = dijkstra(X, reversed_graph);

    int maxDist = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (distance_from_X[i] != INT_MAX && distance_to_X[i] != INT_MAX)
        {
            maxDist = max(maxDist, distance_from_X[i] + distance_to_X[i]);
        }
    }

    cout << maxDist;

    return 0;
}
