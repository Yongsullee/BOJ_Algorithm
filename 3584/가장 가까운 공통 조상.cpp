#include <iostream>
#include <vector>
using namespace std;

int T, N;
vector<int> parent, depth;

void FindDepth(int node, int d) {
    depth[node] = d;
    for (int i = 1; i <= N; ++i) {
        if (parent[i] == node) {
            FindDepth(i, d + 1);
        }
    }
}

int LCA(int u, int v) {
    while (depth[u] != depth[v]) {
        if (depth[u] > depth[v]) {
            u = parent[u];
        } else {
            v = parent[v];
        }
    }

    while (u != v) {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;

        parent = vector<int>(N + 1, 0);
        depth = vector<int>(N + 1, 0);

        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;

            parent[v] = u;
        }

        int root;
        for (int i = 1; i <= N; ++i) {
            if (parent[i] == 0) {
                root = i;
                break;
            }
        }

        FindDepth(root, 0);

        int u, v;
        cin >> u >> v;

        cout << LCA(u, v) << '\n';
    }

    return 0;
}
