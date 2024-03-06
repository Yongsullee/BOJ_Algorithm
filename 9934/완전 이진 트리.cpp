#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MAX 1025

int K, InOrder[MAX];
vector<int> tree[MAX];

void MakeTree(int level, int start, int end)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;
    int root = InOrder[mid];

    tree[level].push_back(root);

    // #1. 왼쪽 서브트리
    MakeTree(level + 1, start, mid - 1);
    // #2. 오른쪽 서브트리
    MakeTree(level + 1, mid + 1, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;

    int n = (1 << K) - 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> InOrder[i];
    }

    // 재귀 호출, 중위 순회를 통해 완전 이진 트리 구성
    MakeTree(0, 0, n - 1);

    for (int i = 0; i < K; ++i)
    {
        for (int j = 0; j < tree[i].size(); ++j)
        {
            cout << tree[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}