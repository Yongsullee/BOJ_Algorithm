#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // 간선 목록, pair < 가중치, 인접 정점 >
    vector<vector<pair<int, int>>> graph(N + 1);
    // 방문 여부
    vector<bool> visited(N + 1, false);
    // 우선순위 큐, 간선의 가중치 기준 최소 힙 구성
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // MST 가중치의 합
    int MSTWeight = 0;
    // MST 목록 중 최대 가중치
    int maxWeight = INT_MIN;
    // 그래프 구성
    while (M--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({weight, to});
        graph[to].push_back({weight, from});
    }

    // 솔린 알고리즘 수행
    pq.push({0, 1});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[node])
            continue;
        // 방문 여부 체크
        visited[node] = true;
        // 최소 가중치의 합
        MSTWeight += weight;
        // MST의 최대 가중치 값 갱신
        if (maxWeight < weight)
            maxWeight = weight;
        // 현재 정점의 간선 목록 순회
        for (const auto &edge : graph[node])
        {
            if (!visited[edge.second])
            {
                pq.push(edge);
            }
        }
    }

    cout << MSTWeight - maxWeight;

    return 0;
}