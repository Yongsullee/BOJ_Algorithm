#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N;

// #1. 간선 구조체
struct Edge
{
    int fromIdx, toIdx;
    double weight;
    
    Edge(int fromIdx, int toIdx, double weight)
    {
        this->fromIdx = fromIdx;
        this->toIdx = toIdx;
        this->weight = weight;
    }
    
    bool operator< (const Edge& other)
    {
        return weight < other.weight;
    }
};

// #2. Union-Find 연산의 Find 연산
int Find(int x, vector<int>& parent)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x], parent);
	}

	return parent[x];
}

// #3. Union-Find 연산의 Union 연산
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

    cin >> N;
    
    cout.precision(2);
    cout << fixed;
    
    vector<pair<double, double>> graph(N);
    vector<Edge> edges;
    
    // #1. 간선 목록 구성
    for(int i=0; i<N; ++i)
    {
        cin >> graph[i].first >> graph[i].second;
        // 간선 목록
        for(int j=i-1; j>=0; --j)
        {
            // graph[i] 와 graph[j]의 거리 계산
            double distance = sqrt(pow(graph[i].first - graph[j].first, 2)
                                   + pow(graph[i].second - graph[j].second, 2));
            edges.push_back(Edge(i, j, distance));
            edges.push_back(Edge(j, i, distance));
        }
    }
    
    // #2. 크루스칼
    // 부모 목록, 랭크 목록
    vector<int> parent(N), rank(N, 0);
    // 최종 최소 비용
    double MSTWeight = 0;
    // 부모 목록 초기화
    for(int i=0; i<N; ++i)
        parent[i] = i;
    // 간선 목록을 가중치 기준 오름차순 정렬
    sort(begin(edges), end(edges));
    // 간선 목록 순회
    for(const auto edge : edges)
    {
        // #1. Find 연산
        int rootX = Find(edge.fromIdx, parent);
        int rootY = Find(edge.toIdx, parent);
        
        // #2. Union 연산 및 최소 비용 계산
        if(rootX != rootY)
        {
            MSTWeight += edge.weight;
            Union(rootX, rootY, parent, rank);
        }
    }
    
    cout << MSTWeight;
    
    return 0;
}