#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int N;
vector<int> v, ans;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    v.resize(N + 1);
    ans.resize(N+1);
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        while (!s.empty() && v[i] > v[s.top()])
        {
            s.pop();
        }

        if (s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top();

        s.push(i);
    }

    for (int i = 1; i <= N; ++i)
        cout << ans[i] << ' ';

    return 0;
}