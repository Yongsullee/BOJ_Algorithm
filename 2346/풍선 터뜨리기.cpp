#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    deque<pair<int, int>> dq;
    
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        dq.push_back({i, tmp});
    }
    
    while(!dq.empty())
    {
        cout << dq.front().first << ' ';
        int cur = dq.front().second;
        dq.pop_front();
        
        if(dq.empty())
            break;
        
        if(cur > 0)
        {
            cur--;
            while(cur != 0)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                cur--;
            }
        }
        else
        {
            while(cur!=0)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                cur++;
            }
        }
    }
    
    return 0;
}