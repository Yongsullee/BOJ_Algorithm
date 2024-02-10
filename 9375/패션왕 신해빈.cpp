#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        unordered_map<string, int> um;

        while (N--)
        {
            string name, type;

            cin >> name >> type;
            um[type]++;
        }

        int ans = 1;
        for (auto it = begin(um); it != end(um); ++it)
        {
            ans *= (it->second + 1);
        }

        cout << ans - 1 << '\n';
    }

    return 0;
}