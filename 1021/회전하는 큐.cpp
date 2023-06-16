#include <iostream>
#include <queue>
using namespace std;

int N, M;
int num;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    deque<int> dq;
    int ans = 0;
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++)
    {
        dq.push_back(i);
    }
    
    while(M--)
    {
        cin >> num;
        int Idx = -1;
        for(int i=0; i<dq.size(); i++)
        {
            if(dq[i] == num)
            {    
                Idx = i;
                break;
            }
        }
        // 1. 왼쪽 회전
        if(Idx < dq.size()-Idx)
        {
            while(1)
            {
                if(dq.front() == num)
                {
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            while(1)
            {
                if(dq.front() == num)
                {
                    dq.pop_front();
                    break;
                }
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    cout << ans;
}