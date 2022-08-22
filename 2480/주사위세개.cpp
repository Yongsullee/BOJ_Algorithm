#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int sameNum = 0;
    int cnt = 0;
    
    if(A != B && A != C && B != C)
    {
        cnt = 0;
        sameNum = max(max(A,B), C);
    }
    else
    {
        if(A == B)
        {
            sameNum = A;
            cnt++;
            if(A == C)
                cnt++;
        }
        else if (A == C)
        {
            sameNum = A;
            cnt++;
            if(A == B)
                cnt++;
        }
        else if (B == C)
        {
            sameNum = B;
            cnt++;
            if(B == A)
                cnt++;
        }   
    }
    int ans =0;
    switch(cnt)
    {
        case 0 :
            ans = sameNum * 100;
            break;
        case 1:
            ans = 1000 + sameNum * 100;
            break;
        case 2:
            ans = 10000 + sameNum * 1000;
            break;
    }
    
    cout << ans << endl;
}