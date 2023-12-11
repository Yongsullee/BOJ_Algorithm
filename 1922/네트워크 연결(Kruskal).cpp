#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

// 간선 구조체
struct Edge
{
    int from, to, weight;
    
    bool operator< (const Edge& other)
    {
        return weight < other.weight;
    }
};

// Union-Find
int Find(int x, vector<int>& parent)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x], parent);
	}

	return parent[x];
}
// Union-Find
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

void Kruskal(vector<Edge>& edges)
{
    // parent, rank -> Union-Find 연산
    vector<int> parent(N+1);
    vector<int> rank(N+1, 0);
    int MSTWeight = 0;
    // parent 초기화
    for(int i=1; i<=N; ++i)
        parent[i] = i;
    
    // 가중치 기준 오름차순 정렬
    sort(begin(edges), end(edges));
    
    // 간선 목록 순회
    for(const auto& edge : edges)
    {
        int rootX = Find(edge.from, parent);
        int rootY = Find(edge.to, parent);
        
        if(rootX != rootY)
        {
            MSTWeight += edge.weight;
            Union(rootX, rootY, parent, rank);
        }
    }
    
    cout << MSTWeight;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    
    // vector 형식의 간선 목록
    vector<Edge> edges(M);
    // 간선 목록 초기화
    for(int i=0; i<M; ++i)
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    
    Kruskal(edges);
    
    return 0;
}