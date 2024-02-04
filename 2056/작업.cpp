#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<vector<int>> graph;
vector<int> time, InDegree;
int maxFinishTime = INT_MIN;

int TopologicalSort()
{
    queue<int> q;
    vector<int> startTime(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        if (InDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 작업 종료 시간
        time[cur] += startTime[cur];
        if (maxFinishTime < time[cur])
            maxFinishTime = time[cur];

        for (const auto &neighbor : graph[cur])
        {
            InDegree[neighbor]--;
            startTime[neighbor] = max(startTime[neighbor], time[cur]);

            if (InDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return maxFinishTime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    graph.resize(N + 1);
    time.resize(N + 1, 0);
    InDegree.resize(N + 1, 0);

    for (int from = 1; from <= N; ++from)
    {
        cin >> time[from];

        int num;
        cin >> num;

        while (num--)
        {
            int to;
            cin >> to;

            graph[from].push_back(to);
            InDegree[to]++;
        }
    }

    cout << TopologicalSort();

    return 0;
}
