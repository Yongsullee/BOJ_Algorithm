#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int N;

void DFS(int cur, unordered_map<int, vector<int>> &tree, vector<int> &parent)
{
    // #1. stack 컨테이너 선언
    stack<int> s;
    //#2. 방문 여부
    vector<bool> visited(tree.size() + 1, false);
    // #3. 루트 노드를 stack에 삽입
    s.push(cur);
    // #4. 루트 노드의 방문여부 체크
    visited[cur] = true;

    while (!s.empty())
    {
        // #1. stack에 가장 마지막으로 들어온 정점
        int cur = s.top();
        // #2. stack에서 top 노드 제거
        s.pop();
        // #3. 현재 노드의 다음 레벨에 위치한 정점들 방문
        if (tree.find(cur) != end(tree))
        {
            for (const auto &next : tree[cur])
            {
                if (!visited[next])
                {
                    // #4. 방문 여부
                    visited[next] = true;
                    // #5. stack에 다음 레벨에 위치하며 현재 노드와 연결된 정점들 삽입
                    s.push(next);
                    // #6. 다음 레벨에 위치한 정점들의 부모 노드를 현재 노드로 업데이트
                    parent[next] = cur;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. unordered_map 형식으로 트리 선언
    unordered_map<int, vector<int>> tree;
    // #2. 부모 노드를 저장할 vector 컨테이너
    vector<int> parent(N + 1, INT_MAX);

    for (int i = 0; i < N - 1; i++)
    {
        int cur, next;
        cin >> cur >> next;

        // #2. 각 노드와 연결되어 있는 인접 정접들 추가
        tree[cur].push_back(next);
        tree[next].push_back(cur);
    }

    DFS(1, tree, parent);

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}
