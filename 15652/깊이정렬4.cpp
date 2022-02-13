#include <iostream>
using namespace std;

int N, M;
int arr[9] = {
    0,
};
bool visited[9] = {
    0,
};

void dfs(int cnt, int num)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= N; i++)
    {
        arr[cnt] = i;
        dfs(cnt + 1, i);
    }
}

int main()
{
    cin >> N >> M;
    dfs(0, 1);
}