#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;

// #1. 간선 구조체
struct Edge
{
    int from, to, weight;
    bool operator<(const Edge &other)
    {
        return weight < other.weight;
    }
};

// #2. Find 연산
int Find(int x, vector<int> &parent)
{
    if (parent[x] != x)
    {
        parent[x] = Find(parent[x], parent);
    }

    return parent[x];
}
// #3. Union 연산
void Union(int rootX, int rootY, vector<int> &parent, vector<int> &rank)
{

    if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else
    {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // #1. 간선 목록
    vector<Edge> edges(M);

    // #2. 간선 목록 구성
    for (int i = 0; i < M; ++i)
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    // #3. 간선 목록을 가중치 기준 오름차순 정렬
    sort(begin(edges), end(edges));

    // #4. 크루스칼
    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    int MSTWeight = 0;
    int maxWeight = INT_MIN;
    for (const auto &edge : edges)
    {
        // Find 연산 : 대표 노드 찾기
        int rootX = Find(edge.from, parent);
        int rootY = Find(edge.to, parent);

        // Union 연산 : 두 대표 노드의 트리가 서로소 집합일 경우, 하나로 합침
        if (rootX != rootY)
        {
            Union(rootX, rootY, parent, rank);
            // MST 목록에 추가
            MSTWeight += edge.weight;
            if (edge.weight > maxWeight)
            {
                maxWeight = edge.weight;
            }
        }
    }

    // MST 목록 중 가장 큰 값은 제외
    cout << MSTWeight - maxWeight;

    return 0;
}