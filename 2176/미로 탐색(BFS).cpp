// #include <iostream>
// #include <vector>
// #include <string>
// #include <climits>
// #include <queue>
// using namespace std;

// typedef pair<int, int> p;

// int N, M;
// vector<vector<int>> maze;

// int dy[] = {1, -1, 0, 0};
// int dx[] = {0, 0, 1, -1};

// void dijkstra(p start)
// {
//     vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
//     // pair < 비용, 정점 위치 >
//     priority_queue<pair<int, p>, vector<pair<int, p>>, greater<pair<int, p>>> pq;

//     pq.push(make_pair(maze[start.first][start.second], start));
//     dist[start.first][start.second] = maze[start.first][start.second];

//     while (!pq.empty())
//     {
//         int curDist = pq.top().first;
//         int cy = pq.top().second.first;
//         int cx = pq.top().second.second;

//         pq.pop();

//         if (curDist > dist[cy][cx])
//             continue;

//         // 인접한 칸을 순회합니다.
//         for (int i = 0; i < 4; i++)
//         {
//             int ny = cy + dy[i];
//             int nx = cx + dx[i];

//             // #1. 다음 인접한 칸이 존재하지 않을 경우
//             if (ny < 0 || ny >= N || nx < 0 || nx >= M || maze[ny][nx] == 0)
//                 continue;

//             int newDist = curDist + maze[ny][nx];
//             if (dist[ny][nx] > newDist)
//             {
//                 pq.push({newDist, {ny, nx}});
//                 dist[ny][nx] = newDist;
//             }
//         }
//     }

//     cout << dist[N - 1][M - 1];
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> N >> M;

//     maze.resize(N, vector<int>(M));

//     for (int i = 0; i < N; ++i)
//     {
//         for (int j = 0; j < M; ++j)
//         {
//             cin >> maze[i][j];
//         }
//     }

//     // 다익스트라 수행
//     dijkstra({0, 0});

//     return 0;
// }

// 2. 정답 코드
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

vector<string> maze;

int N, M;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void bfs(p start)
{
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<p> q;

    dist[start.first][start.second] = 1;
    q.push({start.first, start.second});

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || maze[ny][nx] == '0')
                continue;

            if (dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    cout << dist[N - 1][M - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    maze.resize(N);

    for (int i = 0; i < N; ++i)
        cin >> maze[i];

    bfs({0, 0});

    return 0;
}