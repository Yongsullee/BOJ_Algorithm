#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(vector<string> &grid, vector<vector<bool>> &visited, int x, int y, char color)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid.size())
            if (!visited[nx][ny] && grid[nx][ny] == color)
                dfs(grid, visited, nx, ny, color);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    int normal = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
            {
                dfs(grid, visited, i, j, grid[i][j]);
                normal++;
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == 'G')
                grid[i][j] = 'R';

    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int colorBlind = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j])
            {
                dfs(grid, visited, i, j, grid[i][j]);
                colorBlind++;
            }

    cout << normal << " " << colorBlind << "\n";

    return 0;
}
