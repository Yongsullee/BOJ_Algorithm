#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M, ans;
vector<vector<int>> map;
vector<vector<bool>> visited;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

struct Edge
{
    int from, to, length;
    bool operator<(const Edge &other) const
    {
        return length < other.length;
    }
};

vector<Edge> edges;
vector<int> parent;

void dfs(p cPos, int islandNum)
{
    int cy = cPos.first;
    int cx = cPos.second;

    if (visited[cy][cx])
        return;
    visited[cy][cx] = true;
    map[cy][cx] = islandNum;

    for (int i = 0; i < 4; ++i)
    {
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || map[ny][nx] == 0)
            continue;

        dfs({ny, nx}, islandNum);
    }
}

void FindBridges(int islandNum)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] != islandNum)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int length = 0;
                int ny = i + dy[k];
                int nx = j + dx[k];

                while (1)
                {
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == islandNum)
                        break;

                    if (map[ny][nx] > 0 && length >= 2)
                    {
                        edges.push_back({islandNum, map[ny][nx], length});
                        break;
                    }
                    length++;
                    ny += dy[k];
                    nx += dx[k];
                }
            }
        }
    }
}

int Find(int x)
{
    if (x != parent[x])
    {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int rootX, int rootY)
{
    parent[rootX] = rootY;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    map.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    }

    int island = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visited[i][j] && map[i][j])
            {
                dfs({i, j}, ++island);
            }
        }
    }

    for (int i = 1; i <= island; ++i)
    {
        FindBridges(i);
    }

    parent.resize(island + 1);
    for (int i = 1; i <= island; ++i)
        parent[i] = i;

    sort(begin(edges), end(edges));

    for (auto &edge : edges)
    {
        int rootFrom = Find(edge.from);
        int rootTo = Find(edge.to);

        if (rootFrom != rootTo)
        {
            Union(rootFrom, rootTo);
            ans += edge.length;
        }
    }

    int root = Find(1);
    for (int i = 1; i <= island; ++i)
    {
        if (Find(i) != root)
        {
            cout << "-1\n";
            return 0;
        }
    }

    cout << ans << "\n";

    return 0;
}

// #2. 정답 코드

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, pair<int, int>>> edges;
int parent[MAX * MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, int id)
{
    visited[x][y] = true;
    map[x][y] = id;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && !visited[nx][ny])
        {
            dfs(nx, ny, id);
        }
    }
}

void findBridges(int id)
{
    for (int x = 0; x < N; ++x)
    {
        for (int y = 0; y < M; ++y)
        {
            if (map[x][y] == id)
            {
                for (int dir = 0; dir < 4; ++dir)
                {
                    int len = 0;
                    int nx = x + dx[dir], ny = y + dy[dir];
                    while (nx >= 0 && nx < N && ny >= 0 && ny < M)
                    {
                        if (map[nx][ny] == id)
                            break;
                        if (map[nx][ny] > 0)
                        {
                            if (len >= 2)
                            {
                                edges.push_back({len, {id, map[nx][ny]}});
                            }
                            break;
                        }
                        nx += dx[dir];
                        ny += dy[dir];
                        len++;
                    }
                }
            }
        }
    }
}

int find(int x)
{
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unionFind(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    parent[a] = b;
    return true;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];

    int id = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                dfs(i, j, id++);
            }
        }
    }

    for (int i = 1; i < id; ++i)
    {
        findBridges(i);
    }

    sort(edges.begin(), edges.end());
    for (int i = 1; i < id; ++i)
        parent[i] = i;

    // * 정답 도출을 위해, 각 섬 간의 다리 연결의 가능성 여부를 체크하는 코드에서 에러가 발생.
    int ans = 0;
    int selectedEdges = 0;

    for (auto &e : edges)
    {
        int cost = e.first, a = e.second.first, b = e.second.second;
        if (unionFind(a, b))
        {
            ans += cost;
            selectedEdges++;
            if (selectedEdges == id - 2)
                break;
        }
    }

    if (selectedEdges != id - 2)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}
