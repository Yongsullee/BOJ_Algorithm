#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int T, N, M, K, swarm;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void bfs(p start, vector<vector<int>> &farm, vector<vector<bool>> &visited)
{
    // 큐 선언
    queue<p> q;

    q.push(start);
    visited[start.first][start.second];

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || farm[ny][nx] == 0)
                continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
    // 지렁이 개수 추가
    swarm++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;

        // 2차원 vector 형식의 배추 밭, 2차원 vector 형식의 방문 여부 체크
        vector<vector<int>> farm(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        while (K--)
        {
            int X, Y; // X 는 행, Y는 열

            cin >> X >> Y;
            farm[Y][X] = 1;
        }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (!visited[i][j] && farm[i][j] == 1)
                    bfs({i, j}, farm, visited);

        cout << swarm << '\n';

        swarm = 0;
    }

    return 0;
}