/*
    [문제] : 각 행성을 모두 연결하는 최소 신장 트리 비용
    [설명]
            1. 크루스칼 알고리즘 활용
            2. 크루스칼 알고리즘은 간선 중심의 알고리즘으로, 간선 목록 만들기 + Union-Find 연산 구현
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1001

struct Edge
{
    int u, v, w;
    const bool operator<(const Edge& Other)
    {
        return w < Other.w;
    }
};

int N;
long long MST;
int parent[MAX];
vector<Edge> edges;

int Find(int x)
{
    if(parent[x] != x)
    {
        parent[x] = Find(parent[x]);
    }

    return parent[x];
}

void Union(int rootX, int rootY)
{
    parent[rootX] = rootY;
}

void Kruskal()
{
    // #1. 부모 노드를 자기 자신으로 초기화
    for(int i=0; i<=N; ++i)
        parent[i] = i;

    // #2. 간선 목록을 오름차순 정렬
    sort(begin(edges), end(edges));

    // #3. 간선 목록 순회하며, MST 구성
    for(int i=0; i<(int)edges.size(); ++i)
    {
        int rootX = Find(edges[i].u);
        int rootY = Find(edges[i].v);

        if(rootX != rootY)
        {
            MST += edges[i].w;
            Union(rootX, rootY);
        }
    }

    cout << MST;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 간선 목록 초기화
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            int cost;
            cin >> cost;

            if(i != j)
            {
                edges.push_back(Edge({i,j,cost}));
            }
        }
    }

    // #1. 크루스칼 알고리즘
    Kruskal();

    return 0;
}