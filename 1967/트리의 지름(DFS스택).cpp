#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int N, maxDist;

struct Edge
{
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
    int to, weight;
};

int DFS(int start, vector<vector<Edge>> &tree, vector<bool> &visited)
{
    // 스택 : 정점 + 거리
    stack<pair<int, int>> s;
    // 도착 정점
    int farthestNode = -1;
    // 시작 노드 관련 처리
    visited[start] = true;
    s.push(make_pair(start, 0));

    while (!s.empty())
    {
        int node = s.top().first;
        int dist = s.top().second;
        s.pop();

        for (const auto &edge : tree[node])
        {
            int neighbor = edge.to;
            int weight = edge.weight;
            if (!visited[neighbor])
            {
                // 방문 여부
                visited[neighbor] = true;
                // 거리
                int newDist = dist + weight;
                // 최대 거리 갱신
                if (newDist > maxDist)
                {
                    farthestNode = neighbor;
                    maxDist = newDist;
                }

                s.push(make_pair(neighbor, newDist));
            }
        }
    }

    return farthestNode;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 트리 선언
    vector<vector<Edge>> tree(N + 1, vector<Edge>());
    vector<bool> visited(N + 1, false);
    // #2. 트리 구성
    for (int i = 1; i < N; i++)
    {
        int parent, child, weight;

        cin >> parent >> child >> weight;
        tree[parent].push_back(Edge(child, weight));
        tree[child].push_back(Edge(parent, weight));
    }

    // #1. 첫 번째 DFS
    int dest1 = DFS(1, tree, visited);
    // #2. 두 번째 DFS
    maxDist = 0;
    visited.clear();
    visited.resize(N + 1, false);
    int dest2 = DFS(dest1, tree, visited);

    cout << maxDist;

    return 0;
}