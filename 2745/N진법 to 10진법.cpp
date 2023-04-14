#include <iostream>
#include <cmath>
using namespace std;

string N;
int B;
int ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> B;
    
    int cnt =0;
    for(int i=N.size()-1; i>=0; i--)
    {
        int tmp = 0;
        if(N[i] >= 'A' && N[i] <= 'Z')
        {
            tmp = N[i] - 'A' + 10;
        }
        else
        {
            tmp = N[i] -'0';
        }
        ans += tmp*((int)pow(B, cnt));
        cnt++;
    }
    cout << ans << endl;
}