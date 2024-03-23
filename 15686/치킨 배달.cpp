/*
    @문제 : M개의 치킨집의 조합 별 치킨 거리의 최소 합을 구하는 문제
    @설명
            1. 백트래킹은 '치킨 커리'가 아니라, 치킨집 M개 조합을 구하는데 포커스를 두자
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int ans = INT_MAX;
vector<pair<int, int>> houses, chickens;
vector<int> selected;

// #1. M개의 치킨집 목록을 통해 치킨 거리의 최소 합
int CalculateDist()
{
    int res = 0;
    for (const auto &house : houses)
    {
        int minDist = INT_MAX;
        for (const auto &Idx : selected)
        {
            minDist = min(minDist, abs(house.first - chickens[Idx].first) + abs(house.second - chickens[Idx].second));
        }
        res += minDist;
    }

    return res;
}

void dfs(int cur, int cnt)
{
    // #2. 치킨집 조합을 통해 치킨 거리의 최소 합 계산
    if (cnt == M)
    {
        // #3. 최종 결과 값과 현재 조합의 치킨 거리의 최소 합과 비교하여, 업데이트 수행
        ans = min(ans, CalculateDist());
        return;
    }

    for (int i = cur; i < (int)chickens.size(); ++i)
    {
        selected.push_back(i);
        dfs(i + 1, cnt + 1);
        selected.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int tmp;
            cin >> tmp;

            if (tmp == 1)
                houses.push_back({i, j});
            else if (tmp == 2)
                chickens.push_back({i, j});
        }
    }

    // #1. 백트래킹 활용 최대 M개의 치킨 집 조합
    dfs(0, 0);

    cout << ans;

    return 0;
}