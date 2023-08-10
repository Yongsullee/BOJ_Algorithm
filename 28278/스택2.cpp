#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int N, tmp;
    stack<int> s;
    
    cin >> N;
    while(N--)
    {
        cin >> tmp;
        if(tmp == 1)
        {
            int num;
            cin >> num;
            s.push(num);
        }
        else if(tmp == 2)
        {
            if(!s.empty())
            {
                cout << s.top() << '\n';
                s.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if(tmp == 3)
        {
            cout << (int)s.size() << '\n';
        }
        else if(tmp == 4)
        {
            if(s.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if(tmp == 5)
        {
            if(!s.empty())
            {
                cout << s.top() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }
    
    return 0;
}