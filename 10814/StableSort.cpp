#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comparison(pair<int, string> a,
                pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;
    // 나이, 이름 pair
    pair<int, string> tmp;
    vector<pair<int, string>> vv;
    for (int i = 0; i < N; i++)
    {
        int age;
        cin >> tmp.first >> tmp.second;
        vv.push_back(tmp);
    }
    // 일반 srot가 아닌, stable sort 활용
    stable_sort(vv.begin(), vv.end(), comparison);
    for (int i = 0; i < N; i++)
    {
        cout << vv[i].first << " " << vv[i].second << '\n';
    }
}