#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, res;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--)
    {
        int tmp;
        cin >> tmp;

        pq.push(tmp);
    }

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        res += (first + second);

        pq.push(first + second);
    }

    cout << res;

    return 0;
}