#include <iostream>
#include <vector>
using namespace std;

int N, M;

// #!. DFS 정의
void DFS(int cnt, vector<int> &v)
{
    // #2. 수열의 크기가 M일 때, 정답 출력
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    // #3. 1~N 까지 순차적으로 재귀 호출
    for (int i = 1; i <= N; i++)
    {
        // #4. 수열의 현재 위치에 i를 추가
        v[cnt] = i;
        // #5. 수열의 다음 위치에 대해 DFS를 재귀호출
        DFS(cnt + 1, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // #1. 수열을 담을 vector 컨테이너  선언, M 크기 할당
    vector<int> v(M);

    // #2. DFS 호출, 수열의 0번째 부터 시작
    DFS(0, v);

    return 0;
}