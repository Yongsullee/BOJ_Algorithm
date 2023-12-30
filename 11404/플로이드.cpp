#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    // #1. 2차원 vector 형식의 그래프 선언
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    // #2. 그래프 구성
    while (m--)
    {
        int start, dest, weight;

        cin >> start >> dest >> weight;
        // 여러 노선 존재 가능, 최소 비용을 갖는 노선으로 갱신
        if (graph[start][dest] == 0 || graph[start][dest] > weight)
            graph[start][dest] = weight;
    }

    //#3. 플로이드-워셜 알고리즘(DP와 3번의 중첨 for-loop 활용)
    // 첫 번째 for-loop, k는 경로 정점입니다.
    for (int k = 1; k <= n; ++k)
    {
        // 두 번째 for-loop, i는 시작 정점입니다.
        for (int i = 1; i <= n; ++i)
        {
            // 세 번째 for-loop, j는 도착 정점입니다.
            for (int j = 1; j <= n; ++j)
            {
                // 시작 정점 -> 도착 정점 거리 > 시작 정점 -> 경유 정점 + 경유 정점 -> 도착정점 일 경우, 시작 정점->도착 정점의 최소 거리 비용 갱신
                if (graph[i][k] != 0 && graph[k][j] != 0 && (graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j]))
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // #4. 결과 출력
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                cout << 0 << ' ';
            else
                cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}