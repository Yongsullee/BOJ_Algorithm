#include <iostream>
#include <string>
#include <vector>

#define MAX 30'000'000

using namespace std;

int n, m, w;

struct edge {
	int s, e, t;
};

// 벨만-포드 알고리즘, 시작 정점은 무작위로 임의의 정점으로 설정해도 문제가 없습니다.
bool time_travel(int n, vector<edge> edges) {
	vector<int> dist(n + 1, MAX);

	int s, e, t;

	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;

	int s, e, t;
	while (TC > 0) {
		cin >> n >> m >> w;

		vector<edge> edges;

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (time_travel(n, edges)) cout << "YES\n";
		else cout << "NO\n";

		TC--;
	}

	return 0;
}