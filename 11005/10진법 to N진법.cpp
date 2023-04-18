/*
    #1. Char To Int : - '0'
    #2. Int To Char : + '0'
    #3. 10진법 to N진법

        while(num > 0)
        {
            string ans += (num%N) + '0';
        }

        reverse(begin(ans), end(ans));
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int B;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string ans = "";
    
    cin >> N >> B;
    
    while(N > 0)
    {
        int tmp = (N%B);
        if(tmp >= 10)
        {
            ans += ('A' + (tmp - 10));
        }
        else
        {
            ans += (tmp + '0');
        }
        N /= B;
    }
    
    reverse(begin(ans), end(ans));
    
    cout << ans << endl;
}
