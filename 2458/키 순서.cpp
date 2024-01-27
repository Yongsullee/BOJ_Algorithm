#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    graph.resize(N + 1, vector<int>(N + 1, 0));

    while (M--)
    {
        int a, b;

        cin >> a >> b;

        graph[a][b] = 1;
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int u = 1; u <= N; ++u)
        {
            for (int v = 1; v <= N; ++v)
            {
                if (graph[u][k] != 0 && graph[k][v] != 0 && graph[u][v] == 0)
                {
                    graph[u][v] = 1;
                }
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;

            if (graph[i][j] == 1 || graph[j][i] == 1)
                cnt++;
        }
        if (cnt == N - 1)
            res++;
    }

    cout << res;

    return 0;
}