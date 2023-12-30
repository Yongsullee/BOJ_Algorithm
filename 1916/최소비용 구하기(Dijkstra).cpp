#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;

void Dijkstra(vector<vector<pair<int, int>>> &graph, int start, int dest)
{
    // 최소 거리 목록
    vector<int> dist(n + 1, INT_MAX);
    // 우선 순위 큐, pair< 가중치, 정점 > 에서 가중치를 기준으로 최소 힙(greater, >) 우선순위 큐 구성
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cur_vertex = pq.top().second;
        int cur_dist = pq.top().first;
        pq.pop();

        // '유향 그래프' 이기 때문에, 방문여부 체크 대신 최소 거리 비용의 갱신 여부를 통해 아래 작업 수행 여부를 결정
        if (dist[cur_vertex] < cur_dist)
            continue;

        for (auto &next : graph[cur_vertex])
        {
            int next_vertex = next.first;
            int weight = next.second;

            int new_dist = cur_dist + weight;
            if (dist[next_vertex] > new_dist)
            {
                dist[next_vertex] = new_dist;
                pq.push({new_dist, next_vertex});
            }
        }
    }
    cout << dist[dest];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    // 2차원 벡터 형식의 그래프 구성, pair< 인접 정점, 현재 정점->인접 정점의 가중치
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int start, dest, weight;
        cin >> start >> dest >> weight;
        graph[start].push_back({dest, weight});
    }

    int start, dest;
    cin >> start >> dest;

    Dijkstra(graph, start, dest);

    return 0;
}
