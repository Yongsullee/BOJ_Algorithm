#include <iostream>
#include <string>
#include <stack>
using namespace std;

/*

    1. ')' 가 나올 경우
        -> s.top() 이 '(' 일 경우, -> 레이저, 총 막대 개수 += st.size()
        -> s.top() 이 ')' 일 경우, -> 막대의 끝, stack.pop 하고, 총 막대 개수 += 1
*/

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    string str;
    stack<int> s;
    int ans = 0;
    
    cin >> str;
    
    s.push(str[0]);
    
    for(int i=1; i<(int)str.size(); i++)
    {
        // '(' 일 경우
        if(str[i] == '(')
        {
            s.push(str[i]);   
        }
        // ')' 일 경우
        else if(str[i] == ')')
        {
            // 1. '(' 와 인접 -> 레이저, 총 막대기 + s.size()
            if(str[i-1] == '(')
            {
                s.pop();
                ans += s.size();
            }
            // 2. '(' 와 인접하지 않다 -> 막대기, 총 막대기 + 1
            else if(str[i-1] == ')')
            {
                ans++;
                s.pop();
            }
        }
    }
    
    cout << ans;
    
    return 0;
}