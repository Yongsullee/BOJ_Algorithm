#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    // 수행 감소
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
     ll X;
    int N;
    
    cin >> X;
    cin >> N;
    
    ll total = 0;
    for(int i=0; i<N; i++)
    {
        ll a; int b;
        
        cin >> a >> b;
        total += a * b;
    }
    
    if(total == X)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}