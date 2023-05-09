#include <iostream>
#include <string>
#include <stack>
using namespace std;

int T;
string str;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> T;
    while(T--)
    {
        cin >> str;
        stack<char> s;
        string ans = "YES";
        for(int i=0; i<str.size(); i++)
        {
            if(str[i] == '(')
            {
                s.push(str[i]);
            }
            else if(!s.empty() && str[i] == ')' && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                ans = "NO";
                break;
            }
        }
        if(!s.empty())
            ans = "NO";
        
        cout << ans << endl;
    }
}