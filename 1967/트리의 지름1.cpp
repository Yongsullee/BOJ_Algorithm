/*
*   목적:
*       "무 방향" 간선을 갖는 트리의 지름을 구합니다.
*   설명:
*       1. 먼저, 트리의 지름은 임의의 두 점 사이의 거리(간선의 총 합)중 가장 큰 값을 의미합니다.
*       2. 임의의 한 점에서 시작해 가장 먼 정점을 구하고, 해당 정점으로 부터 다시 가장 먼 정점을 구해 길이의 총 합을 구합니다.
*       3. 무 방향 그래프(트리)를 가정하기 때문에, 간선 목록을 구성할 때 Parent -> Child 뿐만 아니라 Child -> Parent도 고려합니다.
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX_SIZE 10001

struct Edge
{
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

vector<vector<Edge>> Tree(MAX_SIZE);
vector<bool> visited(MAX_SIZE, false);
int MaxDist, FarthestNode;

void DFS(int cur, int dist, vector<bool>& visited)
{
    visited[cur] = true;
    
    if(dist > MaxDist)
    {
        MaxDist = dist;
        FarthestNode = cur;
    }
    
    for(auto& edge : Tree[cur])
    {
        int to = edge.to;
        int weight = edge.weight;
        if(!visited[to])
        {
            DFS(to, dist+weight, visited);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n;
    
    cin >> n;
    
    for(int i=0; i<n-1; i++)
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        Tree[parent].push_back(Edge(child, weight));
        Tree[child].push_back(Edge(parent, weight));
    }
    
    DFS(1, 0, visited);
    
    MaxDist = 0;
    visited.clear();
    visited.resize(MAX_SIZE, false);
    DFS(FarthestNode, 0, visited);
    
    cout << MaxDist;
    
    return 0;
}