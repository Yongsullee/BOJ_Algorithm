#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, M;
vector<vector<int>> box;
queue<p> q;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs()
{
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || box[ny][nx] != 0)
                continue;

            box[ny][nx] = box[cy][cx] + 1;
            q.push(make_pair(ny, nx));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    box.resize(N, vector<int>(M));

    // #1. 익은 토마토의 위치를 모두 큐에 삽입해줍니다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    // #2. bfs를 수행하며, 주변 안익은 토마토들의 익게된 날짜를 기록해줍니다.
    bfs();

    // #3. 안익은 토마토가 존재하는지 확인하고, 최대 일자를 기록합니다.
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (box[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            result = max(result, box[i][j]);
        }
    }

    cout << result - 1;

    return 0;
}