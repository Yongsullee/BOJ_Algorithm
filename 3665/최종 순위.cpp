/*
    문제 : 바뀐 순위, 일관성 및 가능성 확인
    설명
            1. 먼저, 윗 랭크 정점은 그보다 아래 있는 랭크 정점과 모두 간선을 갖는다.
            2. 순위가 바뀐 정점 쌍 끼리 간선 방향을 바꾸고, 진입 차수 값을 변경한다.
            3. 위상 정렬을 수행하고, 정상적으로 모든 정점이 순서를 가지면 성공, 아니면 실패
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NO_ANSWER "IMPOSSIBLE"

int T, n, m;

void TopologicalSort(vector<vector<int>> &adjMatrix, vector<int> &InDegree)
{
    // 큐 자료구조
    queue<int> q;
    vector<int> res;
    // 진입차수 0인 정점을 큐에 삽입
    for (int i = 1; i <= n; ++i)
    {
        if (InDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        res.push_back(cur);

        for (int neighbor = 1; neighbor <= n; ++neighbor)
        {
            if (!adjMatrix[cur][neighbor])
                continue;

            if (--InDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if ((int)res.size() == n)
    {
        for (int i = 0; i < (int)res.size(); ++i)
            cout << res[i] << ' ';

        cout << '\n';
    }
    else
    {
        cout << NO_ANSWER << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> n;

        vector<int> lastYear(n + 1);
        vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1));
        vector<int> InDegree(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            cin >> lastYear[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            int curNode = lastYear[i];
            for (int j = i + 1; j <= n; ++j)
            {
                int nextNode = lastYear[j];
                adjMatrix[curNode][nextNode] = 1;
                InDegree[nextNode]++;
            }
        }

        cin >> m;

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;

            if (adjMatrix[u][v])
            {
                adjMatrix[u][v] = 0;
                adjMatrix[v][u] = 1;

                InDegree[u]++;
                InDegree[v]--;
            }
            else
            {
                adjMatrix[v][u] = 0;
                adjMatrix[u][v] = 1;

                InDegree[v]++;
                InDegree[u]--;
            }
        }
        TopologicalSort(adjMatrix, InDegree);
    }

    return 0;
}