#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 2차원 vector 형식의 인접 행렬과 부모 목록 선엉
    vector<int> v(N, 0);
    vector<vector<int>> adjMatrix(N, v);
    vector<vector<int>> parents(N, v);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> adjMatrix[i][j];
        }
    }

    // #2. 각 정점을 시작 정점으로 하는 BFS 수행
    for (int start = 0; start < N; ++start)
    {
        vector<bool> visited(N, false);
        queue<int> q;

        q.push(start);
        // BFS 수행
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < N; ++neighbor)
            {
                // adjMatrix[현재 정점][인접 정점]이 0이 아니라면, BFS 계속 잰행하고 parents[start] 목록을 업데이트 해줍니다.
                if (!visited[neighbor] && adjMatrix[cur][neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parents[start][neighbor] = 1;
                }
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << parents[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}