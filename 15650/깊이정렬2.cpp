#include <iostream>
#include <vector>
using namespace std;

int N, M;

void DFS(int cnt, int cur, vector<int> &v, vector<bool> &visited)
{
    // #1. M개의 수열이 완성되면, 정답 출력
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    // #2. 'cur'을 통해 현재 레벨 부터 깊이 우선 탐색 수행
    for (int i = cur; i <= N; i++)
    {
        // #3. 방문 여부 체크
        if (!visited[i])
        {
            // #4. 방문 여부 체크
            visited[i] = true;
            // #5. 수열에 다음 방문 정점 추가
            v[cnt] = i;
            // #6. 수열의 다음 위치, 그리고 다음 레벨에 대한 깊이 우선 탐색 재귀 호출
            DFS(cnt + 1, i + 1, v, visited);
            // #7. 방문 여부 체크
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

    //#1. 방문 여부
    vector<bool> visited(N + 1, false);
    //#2. 수열을 담을 vector 컨테이너
    vector<int> v(M);

    //#3. 깊이 우선 탐색 수행
    DFS(0, 1, v, visited);

    return 0;
}