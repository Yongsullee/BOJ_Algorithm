#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    // pair<절대 값, 원본 값>
    // #1. Compare 함수 객체 : 절대 값 우선 비교, 같다면 원본 값 비교
    auto Compare = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first > b.first;
    };

    // #2. Compare 함수 객체의 정렬 방법에 따른 우선 순위 큐 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(Compare)> pq(Compare);

    cin >> N;

    while (N--)
    {
        int tmp;
        cin >> tmp;

        // #1. tmp 값이 0일 경우, 우선 순위 큐에 새로운 값을 삽입
        if (tmp != 0)
        {
            // pair<절대 값, 원본 값> 형식으로 삽입
            pq.push(make_pair(abs(tmp), tmp));
        }
        // #2. tmp 값이 0이 아닐 경우, "출력"
        else
        {
            // #1. 우선 순위 큐가 비어있지 않을 경우
            if (!pq.empty())
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
            // #2. 우선 순위 큐가 비어있을 경우
            else
            {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}