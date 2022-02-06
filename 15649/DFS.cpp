#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[9] = {
    0,
};
bool visited[9] = {
    0,
};

void dfs(int cnt)
{
    // 수열, 즉 arr의 원소 갯수가 "M"이 되면 출력합니다.
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        // 방문한적이 없다면, 수열에 붙여넣고, 재귀 호출을 실행합니다.
        if (visited[i] == false)
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(cnt + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    dfs(0);
}