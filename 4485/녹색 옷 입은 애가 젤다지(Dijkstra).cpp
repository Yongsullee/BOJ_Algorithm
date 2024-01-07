#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;

int N, problemNum = 1;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dijkstra(vector<vector<int>> &graph)
{
    vector<vector<int>> rupee(N, vector<int>(N, INT_MAX));
    priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> pq;

    rupee[0][0] = graph[0][0];
    pq.push({rupee[0][0], make_pair(0, 0)});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if (rupee[x][y] < cost)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            int new_cost = cost + graph[nx][ny];
            if (rupee[nx][ny] > new_cost)
            {
                pq.push({new_cost, make_pair(nx, ny)});
                rupee[nx][ny] = new_cost;
            }
        }
    }
    return rupee[N - 1][N - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        vector<vector<int>> graph(N, vector<int>(N));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                cin >> graph[i][j];
        }

        // 다익스트라
        cout << "Problem" << ' ';
        cout << problemNum << ':' << ' ';
        cout << dijkstra(graph) << '\n';

        problemNum++;
    }

    return 0;
}