/*
*   [문제] : 중간 부품과 이를 구성하는 기본 부품의 개수가 주어졌을 때, 최종 부품을 구성하는 기본 부품의 총 갯수
*   [설명]
            1. 우선, "최종 부품 -> 기본 부품"의 방향성을 갖는 그래프를 구성한다.(기존의 방식과는 역 방향으로 그래프 구성)
            2. 기본 부품(어떠한 부품으로도 구성할 수 없는 고유 부품)을 찾는다.
            3. 최종 부품을 시작으로 위상정렬을 시작해, DP를 통해 현재 부품을 구성하는데 필요한 중간 혹은 기본 부품의 개수를 계산해 나간다.
            4. 마지막으로 기본 부품과 최종 갯수를 오름차순으로 출력한다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define MAX 101

int N,M;
vector<pair<int,int>> graph[MAX];
int inDegree[MAX] = {0,};
bool base[MAX];
int result[MAX] = {0,};

void TopologicalSort()
{
    queue<int> q;
    q.push(N);
    result[N] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(const auto& p : graph[cur])
        {
            int part = p.first;
            int num = p.second;

            result[part] += result[cur] * num;

            if(--inDegree[part] == 0)
            {
                q.push(part);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    fill_n(base, N+1, true);

    // #1 그래프 구성 : 최종 부품 -> 기본 부품의 방향성 그래프, [현재 부품][{필요 기본 부품, 개수}]
    while(M--)
    {
        // X를 만드는데, Y가 K개 필요함
        int X,Y,K;
        cin >> X >> Y >>K;

        graph[X].push_back({Y,K});
        inDegree[Y]++;
        base[X] = false;
    }

    TopologicalSort();

    // #1. 기본 부품의 번호와 개수를 오름차순으로 출력
    for(int i=1; i<=N; ++i)
        if(base[i])
            cout << i << ' ' << result[i] << '\n';


    return 0;
}