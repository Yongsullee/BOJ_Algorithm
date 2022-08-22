#include <iostream>
#include <stack>
typedef long long ll; 
using namespace std;

int main()
{
    int K;
    ll ans = 0;
    stack<ll> s;
    
    cin >> K;
    for(int i=0; i<K; i++)
    {
        ll num;
        cin >> num;
        
        if(num == 0)
        {
            ans -= s.top();
            s.pop(); 
        }
        else
        {
            ans += num;
            s.push(num);  
        }
    }
    cout << ans << endl;
}