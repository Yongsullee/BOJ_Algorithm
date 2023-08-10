#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    queue<int> q;
    stack<int> s;
    cin >> N;
    
    while(N--)
    {
        int num;
        cin >> num;
        
        q.push(num);
    }
    
    int order = 1;
    while(!q.empty())
    {
        int cur = q.front();
        if(cur == order)
        {
            q.pop();
            order++;
        }
        else
        {
            if(!s.empty() && order == s.top())
            {
                order++;
                s.pop();
            }
            else
            {
                s.push(cur);
                q.pop();
            }
        }
    }
    while(!s.empty())
    {
        if(order == s.top())
        {
            order++;
            s.pop();
        }
        else
        {
            cout << "Sad";
            return 0;
        }
    }
    
    cout << "Nice";
    
    return 0;
}