/*
    @문제 : 0X0 칸에서 시작해 각 칸에 위치한 알파벳의 중복이 없이 가능한 가장 깊은 탐색 거리
    @설명 : DFS와 백트래킹 활용
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

typedef pair<int, int> p;

int R, C, ans = INT_MIN;
vector<string> adjMatrix;
vector<vector<bool>> visited;
vector<bool> alphabet(26, false);
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dfs(p cPos, int cnt)
{
    int cy = cPos.first;
    int cx = cPos.second;

    ans = max(ans, cnt);
    visited[cy][cx] = true;
    alphabet[adjMatrix[cy][cx] - 'A'] = true;

    // #3. 상하좌우 인접 칸들에 대하여 dfs 수행
    for (int i = 0; i < 4; ++i)
    {
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx] || alphabet[adjMatrix[ny][nx] - 'A'])
            continue;

        dfs({ny, nx}, cnt + 1);

        // #3. 백트래킹
        visited[ny][nx] = false;
        alphabet[adjMatrix[ny][nx] - 'A'] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    adjMatrix.resize(R);
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i)
    {
        cin >> adjMatrix[i];
    }

    // #1. 0x0 칸부터 dfs를 수행합니다.
    dfs({0, 0}, 1);

    cout << ans;

    return 0;
}