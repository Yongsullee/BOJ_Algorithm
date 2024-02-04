/*
    [문제] : 선행 관계를 유지하며 그래프의 정점을 나열 한다.
    [설명]
            1. 위상 정렬 알고리즘으로 진입차수 위상정렬을 활용한다.
            2. 일반적으로, 큐를 활용하는 진입차수 위상 정렬에서 더 작은 문제부터 먼저 풀어야되는 조건을 만족시키기 위해 우선순위 큐로 대체
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> InDegree;

void TopologicalSort(vector<vector<int>> &graph)
{
    // #1. 큐를 선언합니다.
    priority_queue<int, vector<int>, greater<int>> pq;

    // #2. 진입 차수가 0인 정점들을 큐에 삽입합니다.
    for (int i = 1; i <= N; ++i)
    {
        if (InDegree[i] == 0)
            pq.push(i);
    }

    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';

        for (const auto &neighbor : graph[cur])
        {
            InDegree[neighbor]--;
            if (InDegree[neighbor] == 0)
            {
                pq.push(neighbor);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    graph.resize(N + 1);
    InDegree.resize(N + 1, 0);

    while (M--)
    {
        int from, to;

        cin >> from >> to;
        graph[from].push_back(to);
        InDegree[to]++;
    }

    TopologicalSort(graph);

    return 0;
}