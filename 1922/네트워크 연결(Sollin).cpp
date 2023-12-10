#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// #1. 간선 구조체
struct Edge {
	int src, dest, weight;
};

// #2. Find 연산
int find(vector<int>& parent, int i) {
	if (parent[i] == i)
		return i;
	return parent[i] = find(parent, parent[i]);
}
// #3. Union 연산 
void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
	int rootX = find(parent, x);
	int rootY = find(parent, y);

	if (rank[rootX] < rank[rootY])
		parent[rootX] = rootY;
	else if (rank[rootX] > rank[rootY])
		parent[rootY] = rootX;
	else {
		parent[rootY] = rootX;
		rank[rootX]++;
	}
}

void sollin(vector<Edge>& edges, int N, int M) {
	// #1.parent 목록, rank 목록 : Union-Find의 최적화,
	vector<int> parent(N + 1), cheapest(N + 1), rank(N + 1, 0);

	// #2. 총 컴포넌트 수, MST의 가중치 합
	int numComponents = N, MSTweight = 0;

	// #3. 부모 목록 초기화
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	// #4. 총 컴포넌트가 1개가 될 때까지 진행되는 솔린 알고리즘
	while (numComponents > 1) {
		fill(cheapest.begin(), cheapest.end(), -1);

		// 1.	간선 목록 순회하며, 각 간선의 시작 노드와 도착 노드가 속해 있는 트리/집합의 루트/대표 노드
		//		를 인덱스로, 해당 트리/집합의 간선들 중 최소 가중치를 갖는 간선을 찾는다.
		for (int i = 0; i < M; i++) {
			int set1 = find(parent, edges[i].src);
			int set2 = find(parent, edges[i].dest);

			if (set1 == set2)
				continue;
			else {
				if (cheapest[set1] == -1 || edges[cheapest[set1]].weight > edges[i].weight)
					cheapest[set1] = i;
				if (cheapest[set2] == -1 || edges[cheapest[set2]].weight > edges[i].weight)
					cheapest[set2] = i;
			}
		}

		// 2.	각 집합의 최소 가중치 목록을 순회하며, 각 최소 가중치 간선의 시작 노드와 도착노드가
		//		속한 트리/집합의 루트/대표 노드들을 구해 Union 연산하여, 두 집합을 합친다.
		for (int i = 1; i <= N; i++) {
			if (cheapest[i] != -1) {
				int set1 = find(parent, edges[cheapest[i]].src);
				int set2 = find(parent, edges[cheapest[i]].dest);

				if (set1 == set2)
					continue;
				MSTweight += edges[cheapest[i]].weight;
				Union(parent, rank, set1, set2);
				numComponents--;
			}
		}
	}

	cout << MSTweight;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M);

	for (int i = 0; i < M; i++)
		cin >> edges[i].src >> edges[i].dest >> edges[i].weight;

	sollin(edges, N, M);

	return 0;
}