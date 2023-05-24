#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a;

int main()
{
    cin >> n;
    
    stack<int> s;
    vector<char> v;
    int cnt = 1;
    
    for(int i=0; i<n; i++)
    {
        cin >> a;
        
        while(cnt <= a)
        {
            s.push(cnt);
            cnt++;
            v.push_back('+');
        }
        
        if(s.top() == a)
        {
            s.pop();
            v.push_back('-');
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    
    for(auto c : v)
    {
        cout << c << '\n';
    }
    
}