// 실패 코드, 이유는 몰루?

#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

#define MAX 100001

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    // #1. 최소 비용 목록
    vector<int> dist(MAX, 0);
    // deque 활용
    deque<int> dq;

    dq.push_front(N);
    dist[N] = 1;

    while (!dq.empty())
    {
        int cur_vertex = dq.front();
        dq.pop_front();

        if (cur_vertex == K)
        {
            cout << dist[cur_vertex] - 1;
            break;
        }

        // #1. 순간 이동일 경우, 방문 여부 체크, 거리 비용 변화 없음, deque의 앞으로 2*cur_vertex 삽입
        if (cur_vertex * 2 < MAX && dist[cur_vertex * 2] == 0)
        {
            dist[cur_vertex * 2] = dist[cur_vertex];
            dq.push_front(cur_vertex * 2);
        }
        // #2. 달리기 +1 일 경우, 방문 여부 체크, 거리 비용 변화 +1, deque의 뒤로 1+cur_vertex 삽입
        if (cur_vertex + 1 < MAX && dist[cur_vertex + 1] == 0)
        {
            dist[cur_vertex + 1] = dist[cur_vertex] + 1;
            dq.push_back(cur_vertex + 1);
        }
        // #3. 달리기 -1 일 경우, 방문 여부 체크, 거리 비용 변화 +1, deque의 뒤로 cur_vertex-1 삽입
        if (cur_vertex - 1 >= 0 && dist[cur_vertex - 1] == 0)
        {
            dist[cur_vertex - 1] = dist[cur_vertex] + 1;
            dq.push_back(cur_vertex - 1);
        }
    }

    return 0;
}

//****************************************************************************************************

// 정답 코드, 우선순위 큐 활용

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    // 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(MAX, false);

    pq.push({0, N});
    visited[N] = true;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dist = pq.top().first;

        pq.pop();

        if (cur == K)
        {
            cout << dist;
            break;
        }

        if (cur * 2 < MAX && !visited[cur * 2])
        {
            visited[cur * 2] = true;
            pq.push({dist, cur * 2});
        }
        if (cur + 1 < MAX && !visited[cur + 1])
        {
            visited[cur + 1] = true;
            pq.push({dist + 1, cur + 1});
        }
        if (cur - 1 >= 0 && !visited[cur - 1])
        {
            visited[cur - 1] = true;
            pq.push({dist + 1, cur - 1});
        }
    }

    return 0;
}