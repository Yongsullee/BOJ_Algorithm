#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, K;
int moveType[3] = {1, -1, 2};

void bfs()
{
    int minTime = 0;
    queue<p> q;
    vector<bool> visited(100001, false);

    q.push({N, 0});
    visited[N] = true;

    while (!q.empty())
    {
        int cPos = q.front().first;
        int cTime = q.front().second;
        q.pop();

        if (cPos == K)
        {
            minTime = cTime;
            break;
        }

        for (int i = 0; i < 3; ++i)
        {
            // 다음 위치 계산
            int nPos;
            if (i < 2)
            {
                nPos = cPos + moveType[i];
            }
            else
            {
                nPos = cPos * moveType[i];
            }
            // 방문 여부 + 범위 내 존재하는지 여부
            if (nPos >= 0 && nPos <= 100000 && !visited[nPos])
            {
                visited[nPos] = true;
                q.push({nPos, cTime + 1});
            }
        }
    }

    cout << minTime;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    bfs();

    return 0;
}