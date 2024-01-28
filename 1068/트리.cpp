#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, rootIdx, deleteNode, leaves;
vector<int> tree;
vector<bool> visited;

void dfs(int node)
{
    bool IsLeaf = true;
    visited[rootIdx] = true;
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i] && tree[i] == node)
        {
            IsLeaf = false;
            dfs(i);
        }
    }
    if (IsLeaf)
        leaves++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    tree.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; ++i)
    {
        cin >> tree[i];
        if (tree[i] == -1)
            rootIdx = i;
    }

    cin >> deleteNode;
    visited[deleteNode] = true;

    if (deleteNode != rootIdx)
    {
        dfs(rootIdx);
    }

    cout << leaves;

    return 0;
}