#include <iostream>
#include <vector>
using namespace std;

int N, M;

// #1. 깊이 우선 탐색 함수 정의
void DFS(int cnt, int cur, vector<int> &v)
{
    //#1. 수열의 크기가 M일 때, 수열 출력
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // #2. 수열의 크기가 M보다 작을 때, 깊이 우선 탐색 수행
    for (int i = cur; i <= N; i++)
    {
        // #3. 수열의 현재 위치에 값을 삽입
        v[cnt] = i;
        // #4. 수열의 다음 위치에 현재 값부터 깊이 우선 탐색 재귀적으로 수행
        DFS(cnt + 1, i, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // #1. 수열을 담을 vector 컨테이너 선언
    vector<int> v(M);

    // #2. 1부터 시작하는 재귀 호출 수행
    DFS(0, 1, v);

    return 0;
}