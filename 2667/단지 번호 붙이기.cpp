#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<int> complex;

int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void bfs(p house)
{
    queue<p> q;
    int cnt = 1;

    q.push(house);
    visited[house.first][house.second] = true;

    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= N || ny < 0 || nx >= N || nx < 0 || map[ny][nx] == 0 || visited[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = true;
            cnt++;
        }
    }

    complex.push_back(cnt);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    // 입력 관련 주의 사항 : 공백없이 주어지는 정수 입력은 "%1d"를 활용하는 scanf를 활용합니다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%1d", &map[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!visited[i][j] && map[i][j] == 1)
                bfs({i, j});

    sort(begin(complex), end(complex));

    cout << complex.size() << '\n';
    for (int i = 0; i < (int)complex.size(); ++i)
        cout << complex[i] << '\n';

    return 0;
}