#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int cur)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (const auto &node : tree[cur])
    {
        if (visited[node])
            continue;
        dfs(node);
        // #1. 첫 번째 조건, 현재 노드가 얼리어답터가 아닐 경우, 그 자식 노드들은 무조건 얼리어답터
        dp[cur][0] += dp[node][1];
        // #2. 두 번째 조건, 현재 노드가 얼리어답터일 경우, 그 자식 노드들은 얼리 어답터 일 수도, 아닐 수도 있음
        dp[cur][1] += min(dp[node][0], dp[node][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    tree.resize(N + 1);
    dp.resize(N + 1, vector<int>(2));
    visited.resize(N + 1, false);

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;

        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // #1. DFS 수행을 통해 총 얼리 어답터 수 체크
    dfs(1);

    // #2. dp[1][0] 과 dp[1][1] 중 최소값을 출력
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}