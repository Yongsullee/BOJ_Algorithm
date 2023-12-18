#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;

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
    
};

// #3. Union-Find 연산의 Fin연산
int Find(int x, vector<int>& parent)
{
	if (parent[x] != x)
	{
		parent[x] = Find(parent[x], parent);
	}

	return parent[x];
}

// #4. Union-Find 연산의 Union 연산
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
    
    // 소수점 아래 2자리 고정
    cout.precision(2);
    cout << fixed;
    
    // 그래프 선언
    vector<pair<double,double>> graph(N);
    vector<Edge> edges;
    
    // 그래프 구성
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
    
    // 솔린 알고리즘 수행
    // 부모 목록, 랭크 목록
    vector<int> parent(N), rank(N, 0);
    int components = N;
    vector<int> minWeights(edges.size());
    double MSTWeight = 0;
    // 부모 목록 초기화
    for(int i=0; i<N; ++i)
        parent[i] = i;
    
     while(components > 1)
     {
         // 최소 가중치 목록 -1로 초기화
         fill(begin(minWeights), end(minWeights), -1);
         
         // 간선 목록 순회
         for(int i=0; i<edges.size(); ++i)
         {
            // #1. from 과 to의 대표 노드
             int comp1 = Find(edges[i].fromIdx, parent);
             int comp2 = Find(edges[i].toIdx, parent);
             
             if(comp1 == comp2)
                 continue;
             
             // #2. 각 대표 노드의 최소 가중치 갱신
             if(minWeights[comp1] == -1 || edges[minWeights[comp1]].weight > edges[i].weight)
                 minWeights[comp1] = i;
             if(minWeights[comp2] == -1 || edges[minWeights[comp2]].weight > edges[i].weight)
                 minWeights[comp2] = i;
         }
         // #3. 최소 가중치 목록 순회
         for(int i=0; i<minWeights.size(); ++i)
         {
             if(minWeights[i] != -1)
             {
                 int comp1 = Find(edges[minWeights[i]].fromIdx, parent);
                 int comp2 = Find(edges[minWeights[i]].toIdx, parent);
                 
                 if(comp1 == comp2)
                     continue;
                 
                 // #4. 최소 신장 트리 비용 갱신
                 MSTWeight += edges[minWeights[i]].weight;
                 // #5. Union 연산
                 Union(comp1, comp2, parent, rank);
                 // #6. 집합 수 -1 차감
                 components--;
             }
         }
     }
    
    cout << MSTWeight;

    return 0;
}