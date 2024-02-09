#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int> InDegree;

void TopologicalSort()
{
    queue<int> q;
    vector<int> season(N + 1, 0);

    // #1. 진입 차수가 0인 정점들을 큐에 삽입합니다.
    for (int i = 1; i <= N; ++i)
    {
        if (InDegree[i] == 0)
        {
            season[i] = 1;
            q.push(i);
        }
    }

    // #2. 큐 순회
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto neighbor : graph[cur])
        {
            InDegree[neighbor]--;
            // #3. 진입 차수가 0이 되면, 최소 이수 가능 학기 계산 및
            if (InDegree[neighbor] == 0)
            {
                season[neighbor] = max(season[neighbor], season[cur] + 1);
                q.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << season[i] << ' ';
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
        int first, second;

        cin >> first >> second;
        graph[first].push_back(second);
        InDegree[second]++;
    }

    TopologicalSort();

    return 0;
}