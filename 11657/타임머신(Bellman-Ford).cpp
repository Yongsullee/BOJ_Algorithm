#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, cost;
    Edge(int u, int v, int c) : from(u), to(v), cost(c) {}
};

const int INF = 1e9;
int N, M;
vector<long long> dist;
vector<Edge> edges;

bool bellman_ford() {
    dist[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (Edge &e : edges) {
            if (dist[e.from] == INF) continue;
            if (dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == N) return true; // negative cycle detected
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    dist = vector<long long>(N + 1, INF);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(Edge(a, b, c));
    }

    if (bellman_ford()) {
        cout << -1;
    } else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}
