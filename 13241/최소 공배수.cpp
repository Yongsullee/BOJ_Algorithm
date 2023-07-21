/*
*   [유클리드 호제법] : 만약 A>B 일 경우, gcd(A, B)는 B가 0이 될때까지 나누어 B가 0이 되었을 때, A값이 최대 공약수가 됩니다.
*   [최소 공배수] : (A*B) / gcd(A, B)                    
*/

#include <iostream>
using namespace std;

int gcd(long long int a, long long int b)
{
    int c = a%b;
    while(c!=0)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    long long int A, B;
    
    cin >> A >> B;
    
    cout << (A*B)/gcd(A, B);
    
    return 0;
}