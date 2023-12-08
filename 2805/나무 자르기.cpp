#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    // 나무 높이를 저장하는 vector 형식의 컨테이너 선언
    vector<long long> trees(N);

    // 나무 높이 저장
    for (long long i = 0; i < N; ++i)
    {
        cin >> trees[i];
    }

    // 오름차순 정렬
    sort(begin(trees), end(trees));

    // 이분 탐색 : H 값이 낮아 질수록, bringTrees 값이 커진다.
    long long minH = 0;
    long long maxH = trees[(int)trees.size() - 1];
    long long finH = 0;

    while (minH <= maxH)
    {
        // 중간 H 값
        long long midH = (minH + maxH) / 2;
        long long bringTrees = 0;

        // 각 나무에서 H 높이에서 자르고 남은 윗 부분의 높이
        for (int i = 0; i < (int)trees.size(); ++i)
        {
            long long leftTrees = trees[i] - midH;
            // 자르고 남은 부분이 있을 경우에만
            if (leftTrees > 0)
                bringTrees += leftTrees;
        }

        // minH 높이에서 잘랐을 때, 가져갈 나무들의 길이가 M과 같거나 클 경우 = 최소 M개를 가져갈 수 있다.
        if (bringTrees >= M)
        {
            // midH가 finH보다 클 경우, 최대 H값 갱신
            if (finH < midH)
            {
                finH = midH;
            }
            // minH 값을 midH+1값으로 수정한다 : 이미 M개를 가져갈 수 있지만, 최대 H값을 구하기 위해 minH값을 midH+1 값으로 갱신한다.
            minH = midH + 1;
        }
        // midH 높이에서 잘랐을 때, 가져갈 나무들이의 길이가 M이 안될 때 = 최소 M개 가져갈 수 없음
        else
        {
            // maxH 값을 midH-1값으로 수정한다 : 현재 H값으로 M개를 가져갈 수 없으니, maxH 값을 mid-1 값으로 낮춘다.
            // 주의할 점은 maxH 값을 낮춰야 가져갈 수 있는 나무 길이가 더 커진다!
            maxH = midH - 1;
        }
    }

    cout << finH;

    return 0;
}