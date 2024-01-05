#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, M;

void bfs(int start, vector<vector<int>> &graph, vector<int> &distSum)
{
    // 출발 정점으로부터 각 정점까지 걸리는 최단 거리 비용
    vector<int> dist(N + 1, -1);
    // queue 컨테이너
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    // 큐를 활용한 BFS를 수행하며, 각 정점은 한번 씩만 방문하며 최단 거리 비용을 업데이트합니다.
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto &neighbor : graph[cur])
        {
            if (dist[neighbor] == -1)
            {
                q.push(neighbor);
                dist[neighbor] = dist[cur] + 1;
                // 특정 시작 정점으로부터 각 정점까지의 전체-쌍 최단 거리 비용의 합을 저장합니다.
                distSum[start] += dist[neighbor];
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

    // #1. 2차원 vector 형식의 그래프 선언
    vector<vector<int>> graph(N + 1);
    // #2. 각 정점을 시작점으로 하는 전체-쌍 최단 거리 비용의 합을 저장하는 vector 컨테이너
    vector<int> distSum(N + 1, 0);

    // #3. 그래프 구성
    while (M--)
    {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    // #4. 각 정점을 시작 정점으로 하는 BFS 수행
    for (int i = 1; i <= N; ++i)
        bfs(i, graph, distSum);

    // #5. 전체-쌍 최단 거리 비용을 비교하며, 최소 전체-쌍 최단 거리 비용을 가지는 정점을 찾습니다!
    int minIdx = 0;
    int minDist = INT_MAX;

    for (int i = 1; i <= N; ++i)
    {
        if (distSum[i] != 0 && (distSum[i] < minDist || minDist == INT_MAX))
        {
            minIdx = i;
            minDist = distSum[i];
        }
    }

    cout << minIdx;

    return 0;
}