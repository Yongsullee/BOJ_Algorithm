#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int>a,
         pair<int, int> b)
{
    // y 좌표가 같으면, x를 오름차순
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    // y 좌표가 같지 않으면, y를 오름차순
    return a.second < b.second;
}

int main ()
{
    int N, x=0, y=0;
    cin >> N;
    
    vector<pair<int, int>> vv;
    for(int i=0; i<N; i++)
    {
        cin >> x >> y;
        vv.push_back(make_pair(x, y));
    }
    
    sort(vv.begin(), vv.end(), comp);
    
    for(auto x: vv)
    {
        cout << x.first << " " << x.second << '\n';
    }
}