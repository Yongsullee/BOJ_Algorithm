/*
    @문제 : 주어진 그래프의 최소 신장 트리의 가중치의 합을 구합니다.
    @설명
            0. 최소 신장 트리 알고리즘으로 Kruskal 알고리즘을 활용합니다.(간선 중심, Union-Find연산)
            1. 3가지 조건을 만족하는 간선만 최소 신장 트리 간선 목록에 추가합니다.
            2. 간선의 총 개수가 N-1개 보다 작다면, 최소 신장 트리 구성이 불가능하다고 판단합니다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
    const bool operator<(const Edge &other)
    {
        return w < other.w;
    }
};

int N, M;
char MorW[1001];
int parent[1001];
vector<Edge> edges;
vector<Edge> mst;

int Find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }

    return parent[x];
}

bool Union(int x, int y)
{
    int rootX = Find(x);
    int rootY = Find(y);

    if (rootX != rootY)
    {
        parent[rootX] = rootY;
        return true;
    }

    return false;
}

void Kruskal()
{
    int cnt = 0;

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    for (const auto &edge : edges)
    {
        const int u = edge.u;
        const int v = edge.v;
        const int w = edge.w;

        if (MorW[u] == MorW[v])
            continue;

        if (Union(u, v))
        {
            mst.push_back(edge);
            cnt++;
        }
    }

    if (mst.size() < N - 1)
    {
        cout << -1;
    }
    else
    {
        int ans = 0;
        for (const auto &edge : mst)
        {
            ans += edge.w;
        }
        cout << ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        cin >> MorW[i];
    }

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back(Edge({u, v, w}));
    }

    // #1. 가중치 기준 간선 목록을 오름차순 정렬
    sort(begin(edges), end(edges));

    // #2. 최소 신자 트리 알고리즘 Kruskal 알고리즘 호출
    Kruskal();

    return 0;
}