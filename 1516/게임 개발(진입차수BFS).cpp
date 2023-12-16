#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // #1. 2차원 vector 형식의 그래프 선언
    vector<vector<int>> graph(N + 1);
    // #2. 정점 별 건설 시간
    vector<int> time(N + 1, -1);
    // #3. 결과 시간
    vector<int> result(N + 1, 0);
    // #4. 정점 별 진입차수
    vector<int> inDegree(N + 1, 0);

    // #2. 시간 목록 및 2차원 벡터 형식의 그래프 구성
    for (int i = 1; i <= N; ++i)
    {
        cin >> time[i];
        while (true)
        {
            int tmp;
            cin >> tmp;

            if (tmp == -1)
                break;
            // i는 tmp 정점의 인접 정점 목록에 추가
            graph[tmp].push_back(i);
            // i의 진입 차수 +1 증가
            inDegree[i]++;
        }
    }
    // 진입차수와 BFS 활용 위상정렬

    // #1. 큐 선언
    queue<int> q;
    // #2. 진입 차수가 0인 정점들을 큐에 삽입
    for (int i = 1; i <= N; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            // 선행 건물이 없는 건물들은 자신들을 짓는데 걸리는 시간만 필요함
            result[i] = time[i];
        }
    }
    // #3. 큐 순회
    while (!q.empty())
    {
        int building = q.front();
        q.pop();

        for (int i = 0; i < graph[building].size(); i++)
        {
            // 인접 정점 혹은 다음으로 지을 수 있는 빌딩
            int nextBuilding = graph[building][i];
            // 다음 지을 수 있는 빌딩의 최소 시간 갱신
            result[nextBuilding] = max(result[nextBuilding], result[building] + time[nextBuilding]);
            // 진입 차수 -1 차감
            inDegree[nextBuilding]--;
            // 진입 차수가 0이라면 q에 삽입
            if (inDegree[nextBuilding] == 0)
                q.push(nextBuilding);
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << result[i] << '\n';

    return 0;
}