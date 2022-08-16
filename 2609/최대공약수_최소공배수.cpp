#include <iostream>
using namespace std;

int N, M;

/* 1. 최대 공약수 : 유클리드 호제법

    a % b = c
    b % c = d
    d % c = e
    .
    .
    .
    q % r = 0

    gcd = r !
*/
int gcd(int a, int b)
{
    int c = a % b;
    while(c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

// 2. 최소 공배수 : a * b / (a와 b의 최대공약수)
int lcm(int a, int b)
{
    return (a * b)/ gcd(a, b);
}

int main()
{
    // 수행 시간 감소를 위한 라인
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N >> M;

    cout << gcd(N, M) << '\n' << lcm(N, M) << endl;
    
}