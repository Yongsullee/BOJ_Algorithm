#include <iostream>
#include <vector>
using namespace std;

int N, M;

void DFS(int n, vector<int> &v, vector<bool> &visited)
{
    // #1. M 개의 수를 담은 수열 완성 시 정답 출력
    if (n == M)
    {
        for (int i = 0; i < M; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    // #2. M개의 수를 아직 담지 못했을 경우 DFS 계속 진행
    for (int i = 1; i <= N; i++)
    {
        // #!. 미방문 정점일 경우 탐색 진행
        if (!visited[i])
        {
            // #2. 방문 여부 체크
            visited[i] = true;
            // #3. 수열에 현재 정점 추가
            v[n] = i;
            // #4. 수열의 다음 위치에 대한 재귀호출 수행
            DFS(n + 1, v, visited);
            // #5. 방문 여부 초기화
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // #1. 방문 여부
    vector<bool> visited(N + 1, false);
    // #2. 수열을 담을 vector 컨테이너
    vector<int> v(M);

    DFS(0, v, visited);

    return 0;
}
```