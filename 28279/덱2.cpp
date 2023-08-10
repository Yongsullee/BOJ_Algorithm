#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N, X ,tmp;
    deque<int> dq;
    cin >> N;
    
    while(N--)
    {
        cin >> tmp;
        
        if(tmp == 1)
        {
            cin >> X;
            dq.push_front(X);
        }
        else if(tmp == 2)
        {
            cin >> X;
            dq.push_back(X);
        }
        else if(tmp ==3)
        {
            if(!dq.empty())
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(tmp == 4)
        {
            if(!dq.empty())
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(tmp == 5)
        {
            cout << (int)dq.size() << '\n';
        }
        else if(tmp == 6)
        {
            if(dq.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(tmp == 7)
        {
            if(!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            if(!dq.empty())
                cout << dq.back() << '\n';
            else
                cout << -1 << '\n';
        }
    }
    
    return 0;
}