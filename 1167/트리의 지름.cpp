/*
*   문제 : 트리의 지름이란, 트리의 임의의 두 노드 중 거리가 가장 먼 노드 간 길이를 의미합니다.
*   설명 : 먼저, 임의의 한 정점으로 부터 가장 먼 노드를 구하고, 해당 노드로 부터 한번 더 가장 먼 노드를 구합니다.
*   부가 : vector 컨테이너의 resize()에 대해 복기
*/

#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

vector<vector<Edge>> Tree;
int MaxDist, FarthestNode;

void DFS(int cur, int dist, vector<bool>& visited)
{
    visited[cur] = true;

    if (dist > MaxDist)
    {
        MaxDist = dist;
        FarthestNode = cur;
    }

    for (const auto& edge : Tree[cur])
    {
        int to = edge.to;
        int weight = edge.weight;
        if (!visited[to])
        {
            DFS(to, dist + weight, visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V;

    cin >> V;

    // #1. resize
    Tree.resize(V + 1);
    vector<bool> visited(V + 1, false);

    for (int i = 0; i < V; i++)
    {
        int from;
        cin >> from;
        while (1)
        {
            int to;
            cin >> to;
            if (to == -1)
                break;
            int weight;
            cin >> weight;
            Tree[from].push_back(Edge(to, weight));
        }
    }

    DFS(1, 0, visited);

    MaxDist = 0;
    visited.clear(); // #2. 벡터 초기화
    visited.resize(V + 1, false); // #3. 크기 재조정
    DFS(FarthestNode, 0, visited);

    cout << MaxDist;

    return 0;
}
