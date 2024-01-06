#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> M >> N;

    vector<vector<int>> maze(N, vector<int>(M, 0));
    vector<vector<int>> dist(N, vector<int>(M, INF));
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = row[j] - '0';
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (dist[x][y] < cost)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            int nextCost = cost + maze[nx][ny];
            if (dist[nx][ny] > nextCost)
            {
                dist[nx][ny] = nextCost;
                pq.push({nextCost, {nx, ny}});
            }
        }
    }

    cout << dist[N - 1][M - 1] << '\n';

    return 0;
}
