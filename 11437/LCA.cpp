/*
    @문제 : 트리 자료구조에서 두 노드의 가장 가까운 공통 조상 찾기, LCA 알고리즘
    @설명
            1. DFS를 통해 트리의 각 노드에 대한 깊이 값을 찾습니다. 이 과정에서 각 노드의 부모 노드 또한 찾습니다.
            2.위에서 구한 깊이 정보를 통해 더 깊이 있는 노드를 부모 노드 방향으로 이동하며, 두 노드의 깊이 값을 맞춥니다.
            3.두 노드의 깊이가 동일해지면,두 노드가 같은 노드가 될 때까지 부모 노드 방향으로 이동 시키고, 두 노드가 만나는 지점이 두 노드의 LCA가 됩니다.

    @추가 설명

            1. um 대신 vector 활용 : vector 컨테이너가 캐시 효율이 um보다 뛰어나다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M;
unordered_map<int, vector<int>> tree;
vector<int> depth, parent;
vector<bool> visited;
queue<int> q;

int LCA(int u, int v)
{
    // #1. 항상 v가 u보다 더 깊은 노드로 설정
    if (depth[u] > depth[v])
        swap(u, v);

    // #2. 두 노드의 깊이를 맞춰줍니다. v노드를 부모 노드방향으로 이동
    while (depth[u] != depth[v])
        v = parent[v];

    // #3. 두 노드를 부모 노드 방향으로 이동시키며, 가장 가까운 공통 조상을 찾습니다.
    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    depth.resize(N + 1, 0);
    parent.resize(N + 1, -1);
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;

        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    visited[1] = true;
    q.push(1);

    // #1. BFS를 통해 각 노드의 부모 노드, 깊이를 초기화합니다.
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (const auto &node : tree[cur])
        {
            if (!visited[node])
            {
                visited[node] = true;
                depth[node] = depth[cur] + 1;
                parent[node] = cur;
                q.push(node);
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int u, v;

        cin >> u >> v;

        cout << LCA(u, v) << '\n';
    }

    return 0;
}