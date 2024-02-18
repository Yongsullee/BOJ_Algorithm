#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, res;
vector<vector<int>> heights;
vector<vector<bool>> visited;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void bfs(p start, int h)
{
    queue<p> q;

    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || heights[ny][nx] <= h)
                continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    heights.resize(N, vector<int>(N));

    int maxHeight = -1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> heights[i][j];
            maxHeight = max(maxHeight, heights[i][j]);
        }
    }

    for (int h = 0; h <= maxHeight; ++h)
    {
        visited.clear();
        visited.resize(N, vector<bool>(N, false));
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!visited[i][j] && heights[i][j] > h)
                {
                    bfs({i, j}, h);
                    cnt++;
                }
            }
        }
        res = max(res, cnt);
    }

    cout << res;

    return 0;
}