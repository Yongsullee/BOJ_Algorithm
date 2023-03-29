/*
    펠린드롬, 거꾸로 해도 같은 단어인지 찾기
*/

#include <iostream>
#include <string>
using namespace std;

string str;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int ans = 1;
    
    cin >> str;
    
    for(int i=0 ;i<str.size(); i++)
    {
        if(str[i] != str[str.size()-i-1])
        {
            ans = 0;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}