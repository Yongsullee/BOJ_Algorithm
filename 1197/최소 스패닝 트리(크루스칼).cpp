#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int V, E, answer;

// #1. 간선 구조체
struct Edge
{
	int from, weight, to;
	Edge(int from, int to, int weight)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
	}

	bool operator<(const Edge& RightEdge)
	{
		return weight < RightEdge.weight;
	}
};

// #2. Find 연산
int Find(int x, vector<int>& parent)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x], parent);
	}

	return parent[x];
}
// #3. Union 연산
void Union(int rootX, int rootY, vector<int>& parent, vector<int>& rank)
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
    
    cin >> V >> E;
    
    // #1. 간선 목록
    vector<Edge> edges;
    // #2. 부모 목록 : 부모를 자기 자신으로 초기화
    vector<int> parent(V+1);
    for(int i=1; i<=V; ++i)
        parent[i] = i;
    // #3. rank 목록 : 모두 0으로 초기화
    vector<int> rank(V+1, 0);
    
    // #4. 그래프 구성
    while(E--)
    {
        int from, to, weight;
        
        cin >> from >> to >> weight;
        edges.push_back(Edge(from, to, weight));
    }
    // #5. 간선을 weight 기준 오름차순 정렬
    sort(begin(edges), end(edges));
    
    // #6. MST 목록
    for(const auto& edge : edges)
    {
        // #6-1. from 정점과 to 정점의 루트 노드 찾기
        int rootX = Find(edge.from, parent);
        int rootY = Find(edge.to, parent);
        
        if(rootX != rootY)
        {
            answer += edge.weight;
            // #6-2. Union 연산
            Union(rootX, rootY, parent, rank);
        }
    }
    
    cout << answer;
    
    return 0;
}