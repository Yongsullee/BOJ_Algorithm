#include <iostream>
using namespace std;

/*
    목적:
        nCr,경우의 수를 구하는 "조합"을 활용해서 문제를 풉니다.
    설명:
        1. nCr = n! / r!(n-r)!
        2. 분자의 원소 개수와 분모의 원소 개수가 같다!
            L n * (n-1) * (n-1) -> (n-r+1)  / r * (r-1) * (r-2) -> 1
    
*/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int N, R;
        cin >> R >> N;
        
        int tmp = 1;
        int answer = 1;
        
        for(int i=N; i>N-R; i--)
        {
            answer *= i;
            answer /= tmp++;
        }
        cout << answer << '\n';
    }
}