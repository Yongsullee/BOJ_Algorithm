#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N;
    queue<int> q;
    
    cin >> N;

    for(int i=1; i<=N; i++)
    {
        q.push(i);
    }
    
    int cnt = 0;
    while(q.size() > 1)
    {
        if(cnt%2 == 0)
        {
            q.pop();
        }
        else if(cnt%2 == 1)
        {
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    
    cout << q.front();
    
}