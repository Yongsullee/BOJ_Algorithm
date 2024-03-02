/*
    @문제 : 각 정점을 루트 노드로 하는 서브트리의 모든 정점의 개수
    @설명
            1. 루트 노드를 시작으로 DFS를 수행
            2. 이때, 현재 노드를 루트 노드로하는 서브트리의 정점 개수를 재귀적으로 계산
            3. Bottom-Up 형식으로 각 정점을 루트 노드로 하는 서브트리의 개수를 찾는다.
*/

#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<vector<int>> tree;
vector<int> subTree;

int dfs(int cur, int parent)
{
    subTree[cur] = 1;

    for (const auto &neighbor : tree[cur])
    {
        if (neighbor != parent)
        {
            subTree[cur] += dfs(neighbor, cur);
        }
    }

    return subTree[cur];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> R >> Q;

    tree.resize(N + 1);
    subTree.resize(N + 1, 0);

    // #1. 트리 구성
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // #2. 루트 노드를 시작으로 DFS 수행하며, 각 정점이 루트 노드가 되는 서브트리의 모든 정점의 개수 세기
    dfs(R, -1);

    while (Q--)
    {
        int root;

        cin >> root;

        cout << subTree[root] << '\n';
    }

    return 0;
}