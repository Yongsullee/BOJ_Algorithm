#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 100001
#define LOG2_MAX 18 // log2(MAX)

int N, M;
vector<int> graph[MAX];
int depth[MAX];
int parent[MAX][LOG2_MAX];

void dfs(int node, int parent_node)
{
    depth[node] = depth[parent_node] + 1;
    parent[node][0] = parent_node;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (next == parent_node)
            continue;
        dfs(next, node);
    }
}

void fillParent()
{
    for (int j = 1; j < LOG2_MAX; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);
    for (int i = LOG2_MAX - 1; i >= 0; i--)
    {
        if (depth[b] - depth[a] >= (1 << i))
        {
            b = parent[b][i];
        }
    }
    if (a == b)
        return a;
    for (int i = LOG2_MAX - 1; i >= 0; i--)
    {
        if (parent[a][i] != parent[b][i])
        {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);
    fillParent();

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

    return 0;
}
