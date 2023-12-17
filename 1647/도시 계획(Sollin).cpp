#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int N, M;

// #1. 간선 구조체
struct Edge
{
	int from, weight, to;

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

    cin >> N >> M;
    
    vector<Edge> edges(M);
    
    for(int i=0; i<M; ++i)
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    
    // 부모 노드 목록, 최소 가중치 목록, rank 목록
    vector<int> parent(N+1), minWeight(N+1), rank(N+1, 0);
    // 컴포넌트 개수, MST 가중치 합, MST 가중치 중 최대 가중치
    int components = N;
    int MSTWeight = 0;
    int maxWeight = INT_MIN;
    
    // 부모 노드 목록 초기화
    for(int i=1; i<=N; ++i)
        parent[i] = i;
    
    // 솔린 알고리즘 수행
    while(components > 1)
    {
        // 최소 가중치 목록 -1로 초기화
        fill(begin(minWeight), end(minWeight), -1);
        
        // 가중치 목록 순회, 최소 가중치 목록 갱신
        for(int i=0; i<M; ++i)
        {
            int comp1 = Find(edges[i].from, parent);
            int comp2 = Find(edges[i].to, parent);
            
            if(comp1 == comp2)
                continue;
            
            if(minWeight[comp1] == -1 || edges[minWeight[comp1]].weight > edges[i].weight)
                minWeight[comp1] = i;
            if(minWeight[comp2] == -1 || edges[minWeight[comp2]].weight > edges[i].weight)
                minWeight[comp2] = i;
        }
        
        // 최소 가중치가 갱신된 집합에 대해 Union 연산 수행
        for(int i=1; i<=N; ++i)
        {
            if(minWeight[i] != -1)
            {
                int comp1 = Find(edges[minWeight[i]].from, parent);
                int comp2 = Find(edges[minWeight[i]].to, parent);
                
                if(comp1 == comp2)
                    continue;
                // Union 연산
                Union(comp1, comp2, parent, rank);
                // 컴포넌트 -1 차감
                components--;
                // MST 가중치 합에 더해줍니다.
                MSTWeight += edges[minWeight[i]].weight;
                // MST 간선 목록 중 가중치가 최대일 경우 갱신
                if(maxWeight < edges[minWeight[i]].weight)
                    maxWeight = edges[minWeight[i]].weight;
            }
        }
    }
    
    cout << MSTWeight - maxWeight;
    
    return 0;
}